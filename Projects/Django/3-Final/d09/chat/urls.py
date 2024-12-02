from django.urls import path

from .views import ChatIndex, GeneralPage

urlpatterns = [
    path('', ChatIndex.as_view(), name='chat_index'),
    path('general', GeneralPage.as_view(), name='chat_general'),
]
