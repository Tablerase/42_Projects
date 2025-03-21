from django.db import models

# Create your models here.
class Movies(models.Model):
    episode_nb = models.IntegerField(
            primary_key=True,
            null=False,
            )
    title = models.CharField(
            max_length=64,
            unique=True,
            null=False,
            )
    opening_crawl = models.CharField(
            null=True,
            )
    director = models.CharField(
            max_length=32,
            null=False,
            )
    producer = models.CharField(
            max_length=128,
            null=False,
            )
    release_date = models.DateField(
            null=False,
            )

    def __str__(self):
        return self.title.__str__()
