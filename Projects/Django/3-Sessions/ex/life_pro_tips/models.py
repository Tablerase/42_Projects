from django.db import models
from user_manager.models import CustomUser

# Create your models here.

class Tip(models.Model):
    content = models.TextField()
    author = models.ForeignKey(CustomUser, on_delete=models.CASCADE)
    date = models.DateField(auto_now_add=True)
    last_activity = models.DateField(auto_now=True)

    votes = models.ManyToManyField(CustomUser, through='Vote', related_name='votes')

    @property
    def upvote_count(self):
        return Vote.objects.filter(tip=self, vote_type=Vote.UPVOTE).count()

    @property
    def downvote_count(self):
        return Vote.objects.filter(tip=self, vote_type=Vote.DOWNVOTE).count()

class Vote(models.Model):
    UPVOTE = 'U'
    DOWNVOTE = 'D'
    VOTE_CHOICES = [
        (UPVOTE, 'Upvote'),
        (DOWNVOTE, 'Downvote'),
    ]
    user = models.ForeignKey(CustomUser, on_delete=models.CASCADE)
    tip = models.ForeignKey(Tip, on_delete=models.CASCADE)
    vote_type = models.CharField(max_length=1, choices=VOTE_CHOICES)

    class Meta:
        unique_together = ('user', 'tip')