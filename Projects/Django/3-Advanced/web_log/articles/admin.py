from django.contrib import admin

from .models import Article, UserFavoriteArticle


@admin.register(Article)
class ArticleAdmin(admin.ModelAdmin):
    list_display = ('title', 'author', 'created', 'synopsis')
    search_fields = ('title', 'synopsis')
    list_filter = ('created', )
