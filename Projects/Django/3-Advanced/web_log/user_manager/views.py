from django.urls import reverse_lazy
from django.contrib.auth import login, logout, authenticate
from django.contrib.auth.views import LogoutView, LoginView
from django.views.generic import FormView, RedirectView

from .forms import LoginForm


class LoginPage(LoginView):
    authentification_form = LoginForm
    template_name = 'login.html'
    next_page = reverse_lazy('home')


class LogoutLink(LogoutView):
    next_page = reverse_lazy('home')
