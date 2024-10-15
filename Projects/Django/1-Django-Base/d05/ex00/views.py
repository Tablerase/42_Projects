from django.http import HttpResponse
from django.template import loader

# Create your views here.
def markdown(request):
    template = loader.get_template('index.html')
    return HttpResponse(template.render())
