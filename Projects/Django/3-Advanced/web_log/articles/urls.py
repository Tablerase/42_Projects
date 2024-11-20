from django.urls import path

from .views import ArticlesView, HomeView, PublicationsView, DetailsPage

urlpatterns = [
    path('', HomeView.as_view(), name='home'),
    path('articles', ArticlesView.as_view(), name='articles'),
    path('publications', PublicationsView.as_view(), name='publications'),
    path('articles/<int:pk>/', DetailsPage.as_view(), name='details'),
]
