from django import forms
from .models import Movies

class Remove_Title(forms.Form):
    title = forms.ModelChoiceField(queryset=Movies.objects.all(), empty_label="Select a movie")
    title.label = "Movie to remove"
   
