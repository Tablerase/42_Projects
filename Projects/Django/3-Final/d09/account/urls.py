from django.urls import path

from .views import AccountView, LoginView, LogoutView, login_status

urlpatterns = [
    path('', AccountView.as_view(), name='account'),
    path('login', LoginView.as_view(), name='login'),
    path('logout', LogoutView.as_view(), name='logout'),
    path('login_status', login_status, name='login_status'),
]
