from django.test import TestCase
from django.urls import reverse
from django.contrib.auth.models import User

from .models import Article, UserFavoriteArticle


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


class AddToFavoriteTest(TestCase):
    fixtures = ['fixtures/articles.json',
                'fixtures/favorites.json', 'fixtures/users.json']

    def setUp(self):
        self.user = User.objects.create_user(
            username='testuser', password='insecure-password')
        # Assuming you have articles in your fixtures
        self.article = Article.objects.first()
        self.add_favorite_url = reverse('add_to_favorites')

    def test_adding_favorites(self):
        # Logging the user in
        self.client.login(username='testuser', password='insecure-password')

        # Posting form data
        response = self.client.post(self.add_favorite_url, {
                                    'article': self.article.id})

        # Recovering and checking the response
        self.assertEqual(response.status_code, 200)
        self.assertJSONEqual(response.content, {'success': 'Add'})
        # Verifying that the article was added to favorites
        self.assertTrue(UserFavoriteArticle.objects.filter(
            user=self.user, article=self.article).exists())

    def test_adding_favorites_twice_the_same_article(self):
        # Logging the user in
        self.client.login(username='testuser', password='insecure-password')

        # Adding an article to favorites
        self.client.post(self.add_favorite_url, {'article': self.article.id})
        # Trying to add the same article again
        response = self.client.post(self.add_favorite_url, {
                                    'article': self.article.id})

        # Recovering and checking the response
        self.assertEqual(response.status_code, 200)
        self.assertJSONEqual(response.content, {
                             'success': 'Already', 'errors': 'This article is already in your favorites.'})
