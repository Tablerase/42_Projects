from django.views.generic import TemplateView
from django.contrib.auth.mixins import LoginRequiredMixin


class ChatIndex(LoginRequiredMixin, TemplateView):
    login_url = 'login'
    template_name = 'chat.html'


class GeneralPage(LoginRequiredMixin, TemplateView):
    login_url = 'login'
    template_name = 'chat_general.html'

    def get_context_data(self, **kwargs):
        context = super().get_context_data(**kwargs)
        context['room_name'] = 'general'
        return context
