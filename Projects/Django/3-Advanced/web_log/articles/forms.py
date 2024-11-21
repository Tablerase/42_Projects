from django.forms import ModelForm, HiddenInput

from .models import Article, UserFavoriteArticle


class UserFavoriteArticleForm(ModelForm):
    class Meta:
        model = UserFavoriteArticle
        fields = ['article', 'user']
        widgets = {
            'article': HiddenInput(),
            'user': HiddenInput(),
        }
