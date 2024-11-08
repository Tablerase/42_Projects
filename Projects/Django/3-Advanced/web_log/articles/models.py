from django.db import models
from django.contrib.auth.models import User
from django.utils import timesince, timezone

class Article(models.Model):
    title = models.CharField(max_length=64)
    author = models.ForeignKey(User, on_delete=models.CASCADE)
    created = models.DateTimeField(auto_now_add=True)
    synopsis = models.CharField(max_length=312)
    content = models.TextField()

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
