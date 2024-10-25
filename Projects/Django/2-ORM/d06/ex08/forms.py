from django import forms

""" Example of opening_crawl : Phantom Menace
Turmoil has engulfed the Galactic Republic. The taxation of trade routes to outlying star systems is in dispute.
Hoping to resolve the matter with a blockade of deadly battleships, the greedy Trade Federation has stopped all shipping to the small planet of Naboo.
While the congress of the Republic endlessly debates this alarming chain of events, the Supreme Chancellor has secretly dispatched two Jedi Knights, the guardians of peace and justice in the galaxy, to settle the conflict....
"""

class Update_crawl(forms.Form):
    def __init__(self, titles, *args, **kwargs):
        super(Update_crawl, self).__init__(*args, **kwargs)
        self.fields['title'].choices = titles

    title = forms.ChoiceField(choices=[])
    title.label = "Movie to remove"
    opening_crawl = forms.CharField(
            widget=forms.Textarea(
                attrs={'placeholder': 'Enter the new opening crawl here'}
                )
            )

