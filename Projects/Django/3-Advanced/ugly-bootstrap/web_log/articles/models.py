from django.db import models
from django.contrib.auth.models import User
from django.utils import timesince, timezone
from django.utils.translation import pgettext_lazy as _pl


class Article(models.Model):
    title = models.CharField(
        verbose_name=_pl("label Article title", "title"),
        max_length=64)
    author = models.ForeignKey(
        User,
        verbose_name=_pl("label Article author", "author"),
        on_delete=models.CASCADE)
    created = models.DateTimeField(
        verbose_name=_pl("label Article creation date", "created"),
        auto_now_add=True)
    synopsis = models.CharField(
        verbose_name=_pl("label Article synopsis", "synopsis"),
        max_length=312)
    content = models.TextField(
        verbose_name=_pl("label Article content", "content"),
    )

    @property
    def when(self):
        """
        Calculate the time elapsed since the creation of the article.

        Returns:
            str: A human-readable string representing the time elapsed since the article was created.
        """
        return timesince(self.created, timezone.now())

    def __str__(self):
        return self.title.__str__()


class UserFavoriteArticle(models.Model):
    user = models.ForeignKey(User, on_delete=models.CASCADE)
    article = models.ForeignKey(Article, on_delete=models.CASCADE)

    def __str__(self):
        return self.article.__str__()
