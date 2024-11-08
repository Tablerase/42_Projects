from django.shortcuts import render
from django.urls import reverse
from django.views.generic import ListView, RedirectView

from .models import Article, UserFavoriteArticle

class ArticlesView(ListView):
    model = Article
    template_name = 'articles.html'
    context_object_name = 'articles'

class HomeView(RedirectView):
    url = reverse(viewname='Articles')
