from django.shortcuts import render

# Create your views here.
def home(request):
  context = {
    'user': "Test",
  }
  return render(request, 'index.html', context)
