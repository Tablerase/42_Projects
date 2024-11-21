from django.urls import path

from .views import ArticlesView, HomeView, PublicationsView, DetailsPage, FavoritesView, PublishView, AddFavoriteView

urlpatterns = [
    path('', HomeView.as_view(), name='home'),
    path('articles', ArticlesView.as_view(), name='articles'),
    path('articles/<int:pk>/', DetailsPage.as_view(), name='details'),
    path('publications', PublicationsView.as_view(), name='publications'),
    path('publish', PublishView.as_view(), name='publish'),
    path('favorites', FavoritesView.as_view(), name='favorites'),
    path('add_to_favorites', AddFavoriteView.as_view(), name='add_to_favorites'),
]
