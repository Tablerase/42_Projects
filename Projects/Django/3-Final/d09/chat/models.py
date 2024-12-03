from django.db import models
from django.contrib.auth.models import User
from django.utils.timesince import timesince
from django.utils import timezone


class Chatroom(models.Model):
    name = models.CharField(max_length=64)

    def __str__(self):
        return self.name

    def last_messages(self):
        messages = Message.objects.filter(chat_room=self)
        return messages


class Message(models.Model):
    author = models.ForeignKey(
        User, related_name='messages', on_delete=models.CASCADE)
    content = models.TextField()
    chat_room = models.ForeignKey(
        Chatroom, related_name='messages', on_delete=models.CASCADE)
    timestamp = models.DateTimeField(auto_now_add=True, db_index=True)

    @property
    def when(self):
        return timesince(self.timestamp, timezone.now())

    def __str__(self):
        return f'{self.author}: {self.content[:20]}'
