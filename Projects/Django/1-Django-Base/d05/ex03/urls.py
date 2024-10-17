from django.urls import path

from . import views

urlpatterns = [
        path('', views.color_shade, name='color_shade'),
]
