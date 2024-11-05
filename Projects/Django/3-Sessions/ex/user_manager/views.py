from django.shortcuts import render, redirect
from django.http import JsonResponse

from django.contrib.auth import authenticate, login, logout
from .forms import LoginForm, RegisterForm
from .models import CustomUser

def get_session_username(request):
    """
    Retrieve the username from the session data and return it as a JSON response.
    Args:
      request (HttpRequest): The HTTP request object containing session data.
    Returns:
      JsonResponse: A JSON response containing the username. If the username is not found in the session, 'Guest' is returned as the default value.
    """
    username = request.session.get('username', 'Guest')
    return JsonResponse({'username': username})

def login_view(request):
    error_message = None
    if request.method == 'POST':
        form = LoginForm(request.POST)
        if form.is_valid():
            username = form.cleaned_data['username']
            password = form.cleaned_data['password']
            user = authenticate(request, username=username, password=password)
            if user is not None:
                login(request, user)
                return redirect('home')
            else:
                error_message = 'Invalid username or password'
        else:
            error_message = 'Invalid form submission'
    else:
        form = LoginForm()
    context = {
        'form': form, 
        'error_message': error_message
    }
    return render(request, 'login.html', context) 

def register_view(request):
    error_message = None
    if request.method == 'POST':
        form = RegisterForm(request.POST)
        if form.is_valid():
            username = form.cleaned_data['username']
            password = form.cleaned_data['password']
            confirm_password = form.cleaned_data['confirm_password']
            if password == confirm_password:
                if CustomUser.objects.filter(username=username).exists():
                    error_message = 'Username already exists'
                else:
                    user = CustomUser.objects.create_user(username=username, password=password)
                    login(request, user)
                    return redirect('home')
            else:
                error_message = 'Passwords do not match'
        else:
            error_message = 'Invalid form submission'
    else:
        form = RegisterForm()
    context = {
        'form': form,
        'error_message': error_message,
    }
    return render(request, 'register.html', context)

def logout_view(request):
    logout(request)
    next_page = request.GET.get('next') or request.META.get('HTTP_REFERER')
    return redirect('home')