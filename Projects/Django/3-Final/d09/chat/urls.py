from django.urls import path

from .views import ChatIndex, GeneralPage, EvilPage, GoodPage

urlpatterns = [
    path('', ChatIndex.as_view(), name='chat_index'),
    path('general', GeneralPage.as_view(), name='chat_general'),
    path('evil', EvilPage.as_view(), name='chat_evil'),
    path('good', GoodPage.as_view(), name='chat_good'),
]
