from django.shortcuts import render

from .forms import select_character
from .models import people, planets, Movies

# Create your views here.

def many(request):
    if request.method == 'POST':
        # Recover form data
        form = select_character(request.POST)
        if form.is_valid():
            movie_min_realise_date = form.cleaned_data['movie_min_realise_date']
            movie_max_realise_date = form.cleaned_data['movie_max_realise_date']
            planet_diameter_gt = form.cleaned_data['planet_diameter_gt']
            character_gender = form.cleaned_data['character_gender']

            characters_raw = people.objects.filter(
                    movies__release_date__gte = movie_min_realise_date,
                    movies__release_date__lte = movie_max_realise_date,
                    homeworld__diameter__gt = planet_diameter_gt,
                    gender = character_gender,
                    )
            print(characters_raw)
            characters = []
            for char in characters_raw:
                item = {
                        'name': char.name,
                        'gender': char.gender,
                        'homeworld': char.homeworld,
                        'homeworld_diameter': char.homeworld__diameter,
                        'movie': Movies.objects.filter(characters = char.id),
                        }
                characters.append(item)
        else :
            characters = None
    else :
        # Display data
        form = select_character()
        characters = None
    context = {
            'form' : form,
            'characters' : characters
            }
    return render(request, 'character_form.html', context)
