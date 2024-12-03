import json
from asgiref.sync import async_to_sync
from django.contrib.auth.models import User
from channels.generic.websocket import WebsocketConsumer

from .models import Chatroom, Message


class ChatConsumer(WebsocketConsumer):
    def connect(self):
        self.room_name = self.scope['url_route']['kwargs']['room_name']
        self.room_group_name = f'chat_{self.room_name}'

        async_to_sync(self.channel_layer.group_add)(
            self.room_group_name, self.channel_name
        )
        self.accept()

        # Send all previous messages from chat room
        chatroom = Chatroom.objects.get(name=self.room_name)
        messages = chatroom.last_messages()
        if messages is None:
            self.send(text_data=json.dumps({
                "init": True,
                "messages": []
            }))
        else:
            previous_messages = [
                {"message": msg.content, "author": msg.author.username,
                    "timestamp": msg.timestamp.isoformat()}
                for msg in messages
            ]
            self.send(text_data=json.dumps({
                "init": True,
                "messages": previous_messages
            }))

    def disconnect(self, code):
        async_to_sync(self.channel_layer.group_discard)(
            self.room_group_name, self.channel_name
        )

    # Receive message from WebSocket
    def receive(self, text_data):
        text_data_json = json.loads(text_data)
        message = text_data_json["message"]

        # Add a new message to database
        chatroom = Chatroom.objects.get(name=self.room_name)
        new_msg = Message(
            content=message, author=self.scope['user'], chat_room=chatroom)
        new_msg.save()

        # Send message to room group
        async_to_sync(self.channel_layer.group_send)(
            self.room_group_name, {
                "type": "chat.message",
                "message": message,
                "author": self.scope['user'].username,
                "timestamp": new_msg.timestamp.isoformat()
            }
        )

    # Receive message from room group
    def chat_message(self, event):
        message = event["message"]
        author = event.get("author", "Anonymous")
        timestamp = event.get("timestamp", "")

        # Send message to WebSocket
        self.send(text_data=json.dumps({
            "message": message,
            "author": author,
            "timestamp": timestamp
        }))
