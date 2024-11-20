from django.urls import path

from .views import LoginPage, LogoutLink

urlpatterns = [
    path('login', LoginPage.as_view(), name='login'),
    path('logout', LogoutLink.as_view(), name='logout')
]
