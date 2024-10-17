from django import forms 

class CharacterForm(forms.Form):
    charact_name = forms.CharField(label="Character Name", max_length=100)
