from django.shortcuts import render, HttpResponse

# Create your views here.
def init(request):
    sql_query = """
                CREATE TABLE IF NOT EXISTS ex00_movies (
                    episode_nb INT PRIMARY KEY,
                    title VARCHAR(64) UNIQUE NULL,
                    opening_crawl TEXT,
                    director VARCHAR(32) NOT NULL,
                    producer VARCHAR(128) NOT NULL,
                    release_date DATE NOT NULL
                    created TI
                );
    """
