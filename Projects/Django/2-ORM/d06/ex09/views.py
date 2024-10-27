from django.shortcuts import HttpResponse

from .models import people

# Create your views here.

def display(request):
    result = ""
    try:
        # creation of table
        result += '<table border="1">'
        result += '<tr>'
        # recover field keys
        fields = ['name', 'homeworld', 'climate']
        for colname in fields:
            result += f'<td>{colname}</td>'
        result += '</tr>'
        # recover values
        rows = people.objects.filter(homeworld__climate__icontains='windy').select_related('homeworld').order_by('name')
        if rows.exists():
            for row in rows:
                result += '<tr>'
                result += f'<td>{row.name}</td>'
                result += f'<td>{row.homeworld.name}</td>'
                result += f'<td>{row.homeworld.climate}</td>'
                result += '</tr>'
            result += '</table>'
        else:
            raise ValueError
    except Exception as e:
        # Recover error
        # result = f'<p>Error: {str(e)}</p>'
        result = '<p>No data available, please use the following command line before use:<p>'
        result += '<p><strong>python manage.py loaddata exercices_data/ex09_initial_data.json'
    return HttpResponse(result.encode('utf-8'), content_type='text/html')

