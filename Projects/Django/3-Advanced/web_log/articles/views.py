from django.shortcuts import render
from django.urls import reverse
from django.views.generic import ListView, RedirectView

from .models import Article, UserFavoriteArticle


class ArticlesView(ListView):
    model = Article
    template_name = 'articles.html'
    context_object_name = 'articles'
    paginate_by = 10


class HomeView(RedirectView):
    url = 'articles'
