from django.shortcuts import render
from django.contrib.auth import login, logout
from django.http import JsonResponse
from django.views.generic import View
from django.contrib.auth.forms import AuthenticationForm
from django.contrib.auth.views import LoginView as DjangoLoginView, LogoutView as DjangoLogoutView


class LoginView(DjangoLoginView):
    authentication_form = AuthenticationForm
    template_name = 'login.html'

    def form_valid(self, form):
        user = form.get_user()
        login(self.request, user)
        if self.request.headers.get('x-requested-with') == 'XMLHttpRequest':
            return JsonResponse({'success': True, 'message': 'Login successful!'})
        return super().form_valid(form)

    def form_invalid(self, form):
        print(form.errors)
        if self.request.headers.get('x-requested-with') == 'XMLHttpRequest':
            return JsonResponse({'success': False, 'message': form.errors.as_text()}, status=400)
        return super().form_invalid(form)


class LogoutView(DjangoLogoutView):
    def post(self, request, *args, **kwargs):
        logout(request)
        if self.request.headers.get('x-requested-with') == 'XMLHttpRequest':
            return JsonResponse({'success': True, 'message': 'Logout successful!'})
        return super().post(request, *args, **kwargs)


class AccountView(View):
    def get(self, request):
        form = AuthenticationForm()
        return render(request, 'account.html', {'form': form})
