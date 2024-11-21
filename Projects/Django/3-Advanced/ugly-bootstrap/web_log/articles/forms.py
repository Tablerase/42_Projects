from django.forms import ModelForm, HiddenInput

from .models import Article, UserFavoriteArticle


class UserFavoriteArticleForm(ModelForm):
    class Meta:
        model = UserFavoriteArticle
        fields = ['article', ]
        widgets = {
            'article': HiddenInput(),
        }
