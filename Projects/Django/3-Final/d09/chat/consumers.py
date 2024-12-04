import json
from asgiref.sync import async_to_sync
from django.contrib.auth.models import User
from channels.generic.websocket import WebsocketConsumer

from .models import Chatroom, Message


class ChatConsumer(WebsocketConsumer):
    connected_users = {}

    def connect(self):
        self.room_name = self.scope['url_route']['kwargs']['room_name']
        self.room_group_name = f'chat_{self.room_name}'

        # Add user to channel
        async_to_sync(self.channel_layer.group_add)(
            self.room_group_name, self.channel_name
        )
        self.accept()

        # Send all previous messages from chat room
        chatroom = Chatroom.objects.get(name=self.room_name)
        messages = chatroom.last_messages()
        if messages is None:
            self.send(text_data=json.dumps({
                "type": "init",
                "messages": []
            }))
        else:
            previous_messages = [
                {"message": msg.content, "author": msg.author.username,
                    "timestamp": msg.timestamp.isoformat()}
                for msg in messages
            ]
            self.send(text_data=json.dumps({
                "type": "init",
                "messages": previous_messages
            }))

        # Inform groud that a new user join
        async_to_sync(self.channel_layer.group_send)(
            self.room_group_name, {
                "type": "user.status",
                "status": "join",
                "user": self.scope['user'].username,
            }
        )

        # Add user to the connected users list
        if self.room_group_name not in self.connected_users:
            self.connected_users[self.room_group_name] = set()
        self.connected_users[self.room_group_name].add(
            self.scope['user'].username)
        # Send the list of connected users to the group
        async_to_sync(self.channel_layer.group_send)(
            self.room_group_name, {
                "type": "userlist",
                "users": list(self.connected_users[self.room_group_name])
            }
        )

    def disconnect(self, code):
        # Remove user from the connected users list
        self.connected_users[self.room_group_name].remove(
            self.scope['user'].username)

        # Inform group that a user left
        async_to_sync(self.channel_layer.group_send)(
            self.room_group_name, {
                "type": "user.status",
                "status": "left",
                "user": self.scope['user'].username,
            }
        )

        # Send the updated list of connected users to the group
        async_to_sync(self.channel_layer.group_send)(
            self.room_group_name, {
                "type": "userlist",
                "users": list(self.connected_users[self.room_group_name])
            }
        )

        # Remove user from channel
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
            "type": "chat",
            "message": message,
            "author": author,
            "timestamp": timestamp
        }))

    # Receive user status from room group
    def user_status(self, event):
        user = event["user"]
        status = event["status"]

        self.send(text_data=json.dumps({
            "type": "user_status",
            "user": user,
            "status": status,
        }))

    def userlist(self, event):
        users = event["users"]

        self.send(text_data=json.dumps({
            "type": "userlist",
            "users": users,
        }))
