from django.contrib import admin

from .models import Chatroom, Message


class AdminChatRoom(admin.ModelAdmin):
    list_display = ('name', 'last_messages')
    list_filter = ('name', )

    def last_messages(self, obj):
        messages = Message.objects.filter(
            chat_room=obj).order_by('-timestamp')[:10]
        if messages:
            return ", ".join([f"{msg.author}: {msg.content}" for msg in messages])
        return "No message for now"
    last_messages.short_description = 'Last messages'


class AdminMessage(admin.ModelAdmin):
    list_display = ('author', 'content', 'chat_room')


admin.site.register(Chatroom, AdminChatRoom)
admin.site.register(Message, AdminMessage)
