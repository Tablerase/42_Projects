from django.urls import path

from .views import ArticlesView, HomeView, PublicationsView, DetailsPage, FavoritesView

urlpatterns = [
    path('', HomeView.as_view(), name='home'),
    path('articles', ArticlesView.as_view(), name='articles'),
    path('articles/<int:pk>/', DetailsPage.as_view(), name='details'),
    path('publications', PublicationsView.as_view(), name='publications'),
    path('favorites', FavoritesView.as_view(), name='favorites'),
]
