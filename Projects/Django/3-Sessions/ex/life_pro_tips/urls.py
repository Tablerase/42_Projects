from django.urls import path

from . import views

urlpatterns = [
  path('', views.home, name='home'),
  # tips handlers
  path('upvote/<int:tip_id>/', views.upvote_tip, name='upvote_tip'),
  path('downvote/<int:tip_id>/', views.downvote_tip, name='downvote_tip'),
  path('delete_tip/<int:tip_id>/', views.delete_tip, name='delete_tip')
]