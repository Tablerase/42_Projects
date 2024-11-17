from django.urls import path

from .views import ArticlesView, HomeView

urlpatterns = [
    path('', HomeView.as_view(), name='home'),
    path('articles', ArticlesView.as_view(), name='articles'),
]
