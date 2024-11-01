import random
from django.conf import settings
from django.utils import timezone

class RandomNameMiddleware:
  def __init__(self, get_response):
    self.get_response = get_response

  def __call__(self, request):
    now = timezone.now()
    session = request.session

    if 'username' not in session or 'username_expiration_time' not in session or session['username_expiration_time'] < now.isoformat():
      session['username'] = random.choice(settings.RANDOM_USERNAMES)
      expiration_time = now + timezone.timedelta(seconds=42)
      session['username_expiration_time'] = expiration_time.isoformat()

    response = self.get_response(request)
    return response
