from django.forms import ModelForm, Textarea
from .models import Tip

class TipForm(ModelForm):
    class Meta:
        model = Tip
        fields = ['content']
        widgets = {
            'content': Textarea(attrs= {
                'placeholder': 'Enter your tip here...',
                'class': 'form-control', #bootstrap class 
            })
        }
