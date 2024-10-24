from django.urls import path

from . import views
urlpatterns = [
        path('populate', views.populate, name='populate'),
        path('display', views.display, name='display'),
        path('remove', views.remove, name='remove'),
        ]
