from django.shortcuts import HttpResponse, render
import psycopg

# Import db param
from django.conf import settings
db_config = settings.DATABASES["default"]

def init(request):
    try:
        # Connect to db
        with psycopg.connect(**db_config) as conn:
            # Access cursor to perform operations
            with conn.cursor() as cur:
                # Query to create a table
                create_table_query = '''
                CREATE TABLE IF NOT EXISTS ex00_movies (
                    episode_nb SERIAL PRIMARY KEY,
                    title VARCHAR(64) UNIQUE NOT NULL,
                    opening_crawl TEXT NOT NULL,
                    director VARCHAR(32) NOT NULL,
                    producer VARCHAR(128) NOT NULL,
                    release_date DATE NOT NULL
                );
                '''
                # Execute the query
                cur.execute(create_table_query)
                conn.commit() 
                result = 'OK'
    except Exception as e: 
        #Recover error 
        result = e 
    return HttpResponse(request, result)
