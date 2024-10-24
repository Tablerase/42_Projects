from django.shortcuts import HttpResponse, HttpResponseRedirect, render

from .models import Movies
from .forms import Remove_Title

# Create your views here.

def populate(request):
    result = ''
    try:
        records = [
        (1, 'The Phantom Menace', 'George Lucas', 'Rick McCallum', '1999-05-19'),
        (2, 'Attack of the Clones', 'George Lucas', 'Rick McCallum', '2002-05-16'),
        (3, 'Revenge of the Sith', 'George Lucas', 'Rick McCallum', '2005-05-19'),
        (4, 'A New Hope', 'George Lucas', 'Gary Kurtz, Rick McCallum', '1977-05-25'),
        (5, 'The Empire Strikes Back', 'Irvin Kershner', 'Gary Kurtz, Rick McCallum', '1980-05-17'),
        (6, 'Return of the Jedi', 'Richard Marquand', 'Howard G. Kazanjian, George Lucas, Rick McCallum', '1983-05-25'),
        (7, 'The Force Awakens', 'J. J. Abrams', 'Kathleen Kennedy, J. J. Abrams, Bryan Burk', '2015-12-11')
        ]
        for record in records:
            movie, created = Movies.objects.get_or_create(
                    episode_nb=record[0],
                    defaults={
                        'title': record[1],
                        'director': record[2],
                        'producer': record[3],
                        'release_date': record[4],
                        }
                    )
            if created:
                result += f'<p>OK: <strong>{record[1]}</strong></p>\n'
            else:
                result += f'<p><strong>{record[1]}</strong> already exists</p>\n'
    except Exception as e: 
        #Recover error 
        result = f'<p>Error: {str(e)}</p>'
    return HttpResponse(result.encode('utf-8'), content_type='text/html')

def display(request):
    result = ''
    try:
        # creation of table
        result += '<table border="1">'
        result += '<tr>'
        # recover field keys
        fields = [field.name for field in Movies._meta.get_fields()]
        for colname in fields:
            result += f'<td>{colname}</td>'
        result += '</tr>'
        # recover values
        rows = Movies.objects.all()
        for row in rows:
            result += '<tr>'
            for field in fields:
                value = getattr(row, field)
                result += f'<td>{value}</td>'
            result += '</tr>'
        result += '</table>'

    except Exception as e:
        # Recover error
        # result = f'<p>Error: {str(e)}</p>'
        result = '<p>No data available</p>'
    return HttpResponse(result.encode('utf-8'), content_type='text/html')

def remove(request):
    if request.method == 'POST':
        form = Remove_Title(request.POST)
        if form.is_valid():
            to_rm = form.cleaned_data['title']
            try:
                movie = Movies.objects.get(title=to_rm)
                movie.delete()
            except Exception as e:
                result = f'<p>Error: {str(e)}</p>'
                # result = '<p>No data available</p>'
                return HttpResponse(result.encode('utf-8'), content_type='text/html')
        return HttpResponseRedirect('remove')
    else:
        form = Remove_Title()
        context = {
                'form' : form
                }
        return render(request, 'remove_form.html', context)

