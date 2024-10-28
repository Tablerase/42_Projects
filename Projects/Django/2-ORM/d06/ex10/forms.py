from django import forms
from django.utils.http import datetime

from .models import People

class SelectCharacterForm(forms.Form):
    """
    Character select according to gender, movies time period and planet diameter
    """
    movie_min_realise_date = forms.DateField(
            label = 'Movie min realised date',
            widget=forms.SelectDateWidget(
                years=range(1900, datetime.now().year + 1)
                )
            ) 
    movie_max_realise_date = forms.DateField(
            label = 'Movie max realised date',
            widget=forms.SelectDateWidget(
                years=range(1900, datetime.now().year + 1)
                )
            )
    planet_diameter_gt = forms.IntegerField(label = 'Planet diameter greater than')
    character_gender = forms.ChoiceField(
            choices=[('male', 'male'), ('female', 'female'), ('n/a', 'n/a'), ('hermaphrodite', 'hermaphrodite'), ('none', 'none')],
            label = 'Character Gender',
            )

    # Prevent invalid time period
    def clean(self):
        cleaned_data = super().clean()
        movie_min = cleaned_data.get('movie_min_realise_date')
        movie_max = cleaned_data.get('movie_max_realise_date')
        if movie_min and movie_max and movie_min > movie_max:
            raise forms.ValidationError("Movie min realised date cannot be greater than movie max realised date.")
        return cleaned_data
