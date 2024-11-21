from django.urls import path

from .views import LoginPage, LogoutLink, RegisterPage

urlpatterns = [
    path('login', LoginPage.as_view(), name='login'),
    path('logout', LogoutLink.as_view(), name='logout'),
    path('register', RegisterPage.as_view(), name='register'),
]
