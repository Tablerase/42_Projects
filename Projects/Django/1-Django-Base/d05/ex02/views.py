from django.shortcuts import render

# Create your views here.
def form(request):
    context = {
            'active_page': 'form',
            }
    return render(request, 'first_form.html', context)
