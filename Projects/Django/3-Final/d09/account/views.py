from django.http import JsonResponse
from django.views.generic import FormView, TemplateView
from django.contrib.auth.views import LoginView as DjangoLoginView
from django.contrib.auth.views import LogoutView as DjangoLogoutView
from django.contrib.auth import login
from django.contrib.auth.forms import AuthenticationForm


class AccountView(TemplateView):
    template_name = 'account.html'
    content_type = 'text/html'

    form = AuthenticationForm
    extra_context = {
        'form': form,
    }


class LoginView(DjangoLoginView):
    authentication_form = AuthenticationForm

    def form_valid(self, form):
        user = form.get_user()
        login(self.request, user)
        if self.request.is_ajax():
            return JsonResponse({
                'message': 'Login successful!'
            })
        return super().form_valid(form)

    def form_invalid(self, form):
        if self.request.is_ajax():
            return JsonResponse({'message': 'Login failed. Please try again.'}, status=400)
        return super().form_invalid(form)


class LogoutView(DjangoLogoutView):
    next_page = '/'
