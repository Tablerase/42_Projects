from django.shortcuts import render
from django.views.generic import FormView
from django.contrib.auth.views import LoginView, LogoutView
from django.contrib.auth.forms import AuthenticationForm


class AccountView(LoginView):
    authentification_form = AuthenticationForm
    template_name = 'account.html'
    # next_page = reverse_lazy('home')
