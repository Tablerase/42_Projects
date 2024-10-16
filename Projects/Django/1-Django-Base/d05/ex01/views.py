from django.shortcuts import render

# Create your views here.
def django(request):
    return render(request, 'django.html', {'active_page': 'django'})

def display(request):
    return render(request, 'display.html', {'active_page': 'display'})

def template(request):
    # List of Django template tags
    django_tags = [
        'if', 
        'for', 
        'block', 
        'extends', 
        'include', 
        'with', 
        'comment', 
        'filter', 
        'autoescape', 
        'verbatim'
    ]
    
    # Boolean variable
    control = True

    # Context dictionary
    context = {
        'django_tags': django_tags,
        'control': control,
        'active_page': 'template'
    }
    return render(request, 'template.html', context)
