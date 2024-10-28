from django.shortcuts import render
from .forms import SelectCharacterForm
from .models import People, Planets, Movies

def many(request):
    if request.method == 'POST':
        form = SelectCharacterForm(request.POST)
        if form.is_valid():
            movie_min_release_date = form.cleaned_data['movie_min_realise_date']
            movie_max_release_date = form.cleaned_data['movie_max_realise_date']
            planet_diameter_gt = form.cleaned_data['planet_diameter_gt']
            character_gender = form.cleaned_data['character_gender']

            movies = Movies.objects.filter(
                release_date__gte=movie_min_release_date,
                release_date__lte=movie_max_release_date,
                characters__homeworld__diameter__gt=planet_diameter_gt,
                characters__gender=character_gender,
            ).distinct()

            characters = []
            for movie in movies:
                for char in movie.characters.filter(
                    homeworld__diameter__gt=planet_diameter_gt,
                    gender=character_gender
                ).select_related('homeworld'):
                    item = {
                        'name': char.name,
                        'gender': char.gender,
                        'homeworld': char.homeworld.name,
                        'homeworld_diameter': char.homeworld.diameter,
                        'movie': movie.title,
                    }
                    characters.append(item)
        else:
            characters = None
    else:
        form = SelectCharacterForm()
        characters = None

    context = {
        'form': form,
        'characters': characters
    }
    return render(request, 'character_form.html', context)
