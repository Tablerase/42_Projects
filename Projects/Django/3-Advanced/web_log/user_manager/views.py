from django.urls import reverse_lazy
from django.contrib.auth.views import LogoutView, LoginView
from django.views.generic import CreateView
from .forms import LoginForm, RegisterForm


class LoginPage(LoginView):
    authentification_form = LoginForm
    template_name = 'login.html'
    next_page = reverse_lazy('home')


class LogoutLink(LogoutView):
    next_page = reverse_lazy('home')


class RegisterPage(CreateView):
    form_class = RegisterForm
    template_name = 'register.html'
    success_url = reverse_lazy('home')

    def form_valid(self, form):
        user = form.save()
        return super().form_valid(form)
