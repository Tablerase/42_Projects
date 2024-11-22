from django.test import TestCase

from django.urls import reverse
from django.contrib.auth.models import User


class ViewAccessTests(TestCase):
    fixtures = ['fixtures/articles.json',
                'fixtures/favorites.json', 'fixtures/users.json']

    def setUp(self):
        # Testing env variables
        self.username = 'testuser'
        self.password = 'insecure-password'
        self.user = User.objects.create_user(
            username=self.username, password=self.password)
        self.favorites_url = reverse('favorites')
        self.publications_url = reverse('publications')
        self.publish_url = reverse('publish')
        self.login_url = reverse('login')
        self.urls_to_test = [self.favorites_url,
                             self.publications_url, self.publish_url]

    def test_views_url_access(self):
        # Unlogged user
        for url in self.urls_to_test:
            response = self.client.get(url)
            self.assertRedirects(
                response, f"{self.login_url}?next={url}")

        # Logged user
        self.client.login(username=self.username, password=self.password)
        for url in self.urls_to_test:
            response = self.client.get(url)
            self.assertEqual(response.status_code, 200)
