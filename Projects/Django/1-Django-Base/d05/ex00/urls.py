from django.urls import path

from . import views

urlpatterns = [
        path('', views.markdown, name='markdown')
    ]
