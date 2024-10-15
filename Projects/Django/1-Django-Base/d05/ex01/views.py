from django.shortcuts import HttpResponse, loader

# Create your views here.
def django(request):
    template = loader.get_template('django.html')
    return HttpResponse(template.render())

def display(request):
    template = loader.get_template('display.html')
    return HttpResponse(template.render())
