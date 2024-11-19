from django.shortcuts import render
from django.urls import reverse
from django.views.generic import ListView, RedirectView
from django.contrib.auth.decorators import login_required, permission_required

from .models import Article, UserFavoriteArticle


class ArticlesView(ListView):
    model = Article
    template_name = 'articles.html'
    context_object_name = 'articles'
    paginate_by = 10

    def get_context_data(self, **kwargs):
        context = super().get_context_data(**kwargs)
        context['fields'] = [field.name for field in Article._meta.fields]
        return context


@login_required(login_url='/user/login')
class PublicationsView(ListView):
    model = Article
    template_name = 'publications.html'
    context_object_name = 'publications'

    def get_queryset(self):
        return Article.objects.filter(author=self.request.user)


class HomeView(RedirectView):
    url = 'articles'
