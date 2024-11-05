from django.contrib import admin
from .models import Tip, Vote

class TipAdmin(admin.ModelAdmin):
    list_display = ('content', 'author', 'date', 'last_activity', 'upvote_count', 'downvote_count')
    search_fields = ('content', 'author__username')
    list_filter = ('date', 'last_activity')

    def upvote_count(self, obj):
        return Vote.objects.filter(tip=obj, vote_type=Vote.UPVOTE).count()
    upvote_count.short_description = 'Upvotes'

    def downvote_count(self, obj):
        return Vote.objects.filter(tip=obj, vote_type=Vote.DOWNVOTE).count()
    downvote_count.short_description = 'Downvotes'

class VoteAdmin(admin.ModelAdmin):
    list_display = ('user', 'tip', 'vote_type')
    search_fields = ('user__username', 'tip__content')
    list_filter = ('vote_type',)

admin.site.register(Tip, TipAdmin)
admin.site.register(Vote, VoteAdmin)