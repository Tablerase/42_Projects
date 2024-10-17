import logging
from django.conf import settings
from django.shortcuts import HttpResponseRedirect, render

from .forms import CharacterForm

# Create your views here.

# Define a logger for form submission
logger = logging.getLogger('form_submission')

def form(request):
    # Handle Post
    if request.method == 'POST':
        form = CharacterForm(request.POST)
        # Data validation
        if form.is_valid():
            # Logging data ...
            character = form.cleaned_data
            logger.info(f'{character["charact_name"]}') 
            # Redirection after processing
            return HttpResponseRedirect('/ex02/')
    # Other request (GET, ...)
    else:
        form = CharacterForm()
        with open(settings.LOGGING_FORM_HISTORY, 'r') as log_file:
            submission_history = log_file.readlines() 
        context = {
                'submission_history': submission_history,
                'active_page': 'form',
                'form': form,
        }
        return render(request, 'form.html', context)
