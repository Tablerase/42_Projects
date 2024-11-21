from django.shortcuts import render, get_object_or_404
from django.urls import reverse_lazy
from django.views.generic import ListView, RedirectView, DetailView, CreateView
from django.contrib.auth.mixins import LoginRequiredMixin
from django.http import JsonResponse

from .models import Article, UserFavoriteArticle
from .forms import UserFavoriteArticleForm


class ArticlesView(ListView):
    model = Article
    template_name = 'articles.html'
    context_object_name = 'articles'
    paginate_by = 10

    def get_context_data(self, **kwargs):
        context = super().get_context_data(**kwargs)
        context['fields'] = [field.name for field in Article._meta.fields]
        return context


class PublicationsView(LoginRequiredMixin, ListView):
    login_url = reverse_lazy('login')

    model = Article
    template_name = 'publications.html'
    context_object_name = 'publications'

    def get_queryset(self):
        return Article.objects.filter(author=self.request.user)

    def get_context_data(self, **kwargs):
        context = super().get_context_data(**kwargs)
        context['fields'] = [field.name for field in Article._meta.fields]
        return context


class FavoritesView(LoginRequiredMixin, ListView):
    login_url = reverse_lazy('login')

    model = UserFavoriteArticle
    template_name = 'favorites.html'
    context_object_name = 'favorites'

    def get_queryset(self):
        # Recover article from UserFavoriteArticle objects of connected user
        return UserFavoriteArticle.objects.filter(user=self.request.user).select_related('article')

    def get_context_data(self, **kwargs):
        context = super().get_context_data(**kwargs)
        context['favorite_articles'] = [
            fav.article for fav in self.get_queryset()]
        return context


class HomeView(RedirectView):
    url = 'articles'


class DetailsPage(DetailView):
    model = Article
    template_name = 'article_detail.html'
    context_object_name = 'article'

    def get_context_data(self, **kwargs):
        context = super().get_context_data(**kwargs)
        if self.request.user.is_authenticated:
            form = UserFavoriteArticleForm(initial={
                'article': self.get_object(),
            })
            context['form'] = form
        return context


class PublishView(CreateView):
    model = Article
    template_name = 'publish.html'
    success_url = reverse_lazy('home')
    fields = ['title', 'synopsis', 'content']

    def form_valid(self, form):
        form.instance.author = self.request.user
        return super().form_valid(form)


class AddFavoriteView(CreateView):
    model = UserFavoriteArticle
    form_class = UserFavoriteArticleForm
    template_name = 'add_to_favorites.html'
    success_url = reverse_lazy('favorites')

    def form_valid(self, form):
        form.instance.user = self.request.user
        if UserFavoriteArticle.objects.filter(user=self.request.user, article=form.instance.article).exists():
            return JsonResponse({'success': 'Already', 'errors': 'This article is already in your favorites.'})
        self.object = form.save()
        return JsonResponse({'success': 'Add'})

    def form_invalid(self, form):
        return JsonResponse({'success': 'Error', 'errors': form.errors})
