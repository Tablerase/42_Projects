from django import forms

class Remove_Title(forms.Form):
    def __init__(self, titles, *args, **kwargs):
        super(Remove_Title, self).__init__(*args, **kwargs)
        self.fields['title'].choices = titles

    title = forms.ChoiceField(choices=[])
    title.label = "Movie to remove"
   
