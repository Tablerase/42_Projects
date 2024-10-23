from django import forms

import psycopg2
from django.conf import settings

class Remove_Title(forms.Form):
    try:
        with psycopg2.connect(**settings.DB_CONFIG) as conn:
            with conn.cursor() as curs:
                curs.execute("SELECT title FROM ex04_movies")
                curs.fetchall()
    except Exception:
        ...
