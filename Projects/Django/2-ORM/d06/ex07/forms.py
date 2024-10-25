from django import forms
from .models import Movies

class  Update_crawl(forms.Form):
    title = forms.ModelChoiceField(queryset=Movies.objects.all(), empty_label="Select a movie")
    title.label = "Movie to remove"
    opening_crawl = forms.CharField(
            widget=forms.Textarea(
                attrs={'placeholder': 'Enter the new opening crawl here'}
                )
            )

