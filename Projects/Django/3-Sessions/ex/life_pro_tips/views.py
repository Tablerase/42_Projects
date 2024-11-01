from django.shortcuts import render

# Create your views here.
def home(request):
  context = {}
  return render(request, 'home.html', context)

def login_view(request):
    # Implement login logic
    pass

def register_view(request):
    # Implement register logic
    pass

def logout_view(request):
    # Implement logout logic
    pass