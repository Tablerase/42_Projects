from django.urls import path

from . import views

urlpatterns = [
        path('', views.many, name='many'),
        ]
