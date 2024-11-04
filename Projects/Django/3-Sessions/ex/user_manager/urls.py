from django.urls import path

from . import views

urlpatterns = [
  path('get_session_username', views.get_session_username, name='get_session_username'),
  # Auth urls
  path('login/', views.login_view, name='login'),
  path('register/', views.register_view, name='register'),
  path('logout/', views.logout_view, name='logout'),
]
