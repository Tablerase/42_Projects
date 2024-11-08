from django.urls import path
from .views import ArticlesView, HomeView

urlpatterns = [
    path('', HomeView, name='Home'),
    path('articles', ArticlesView, name='Articles'),
]