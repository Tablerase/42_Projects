from django.shortcuts import render
from django.contrib.auth import login, logout
from django.urls import reverse
from django.http import JsonResponse
from django.views.generic import View
from django.contrib.auth.forms import AuthenticationForm
from django.contrib.auth.views import LoginView as DjangoLoginView, LogoutView as DjangoLogoutView
from django.contrib.auth.decorators import login_required
from django.contrib.auth.mixins import LoginRequiredMixin


def login_status(request):
    return JsonResponse({'is_logged_in': request.user.is_authenticated})


class LoginView(DjangoLoginView):
    authentication_form = AuthenticationForm
    template_name = 'login.html'

    def form_valid(self, form):
        user = form.get_user()
        login(self.request, user)
        if self.request.headers.get('x-requested-with') == 'XMLHttpRequest':
            return JsonResponse({'success': True, 'message': 'Login successful!'})
        return super().form_valid(form)

    def get_success_url(self):
        # Override redirection
        next_url = self.request.POST.get(
            self.redirect_field_name) or self.request.GET.get(self.redirect_field_name)
        return next_url or reverse('chat_index')

    def form_invalid(self, form):
        if self.request.headers.get('x-requested-with') == 'XMLHttpRequest':
            return JsonResponse({'success': False, 'message': form.errors})
        return super().form_invalid(form)


class LogoutView(DjangoLogoutView):
    next_page = '/account'

    def get(self, request, *args, **kwargs):
        if self.request.headers.get('x-requested-with') == 'XMLHttpRequest':
            return JsonResponse({
                'username': request.user.username,
            })
        return super().get(request, *args, **kwargs)

    def post(self, request, *args, **kwargs):
        logout(request)
        if self.request.headers.get('x-requested-with') == 'XMLHttpRequest':
            return JsonResponse({'success': True, 'message': 'Logout successful!'})
        return super().post(request, *args, **kwargs)


class AccountView(View):
    def get(self, request):
        form = AuthenticationForm()
        return render(request, 'account.html', {'form': form})
