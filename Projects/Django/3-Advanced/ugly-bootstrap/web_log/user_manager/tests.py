from django.test import TestCase
from django.urls import reverse
from django.contrib.auth.models import User


class RegisterAccess(TestCase):

    def setUp(self):
        # Testing env variables
        self.username = 'testuser'
        self.password = 'insecure-password'
        self.user = User.objects.create_user(
            username=self.username, password=self.password)
        self.register_url = reverse('register')

    def test_register_url_access(self):
        # Unlogged user
        response = self.client.get(self.register_url)
        self.assertEqual(response.status_code, 200)
        self.assertNotContains(response, 'You are already logged in.')


class RegisterFormAccess(TestCase):

    def setUp(self):
        self.username = 'testuser'
        self.password = 'insecure-password'
        self.user = User.objects.create_user(
            username=self.username, password=self.password)
        self.register_url = reverse('register')

    def test_logged_user_register_access(self):
        # Logged user
        self.client.login(username=self.username, password=self.password)
        response = self.client.get(self.register_url)
        self.assertEqual(response.status_code, 200)
        self.assertContains(response, 'You are already logged in.')

    def test_logged_user_register_post(self):
        # Logged user
        self.client.login(username=self.username, password=self.password)
        response = self.client.post(self.register_url, {
            'username': 'newuser',
            'password1': 'newpassword',
            'password2': 'newpassword'
        })
        print(response.content)
        # Verify newuser was not created
        self.assertFalse(User.objects.filter(username='newuser').exists())
        self.assertEqual(response.status_code, 200)
        self.assertContains(response, 'You are already logged in.')
