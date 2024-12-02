from django.db import models
from django.contrib.auth.models import User


class Chatroom(models.Model):
    name = models.CharField(max_length=64)

    def __str__(self):
        return self.name


class Message(models.Model):
    author = models.ForeignKey(
        User, related_name='messages', on_delete=models.CASCADE)
    content = models.TextField()
    chat_room = models.ForeignKey(
        Chatroom, related_name='messages', on_delete=models.CASCADE)
    timestamp = models.DateTimeField(auto_now_add=True, db_index=True)

    def __str__(self):
        return f'{self.author}: {self.content[:20]}'
