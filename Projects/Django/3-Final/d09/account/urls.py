from django.urls import path

from .views import AccountView, LoginView, LogoutView

urlpatterns = [
    path('', AccountView.as_view(), name='account'),
    path('login', LoginView.as_view(), name='login'),
    path('logout', LogoutView.as_view(), name='logout'),
]
