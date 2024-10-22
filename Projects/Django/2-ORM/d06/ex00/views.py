from django.shortcuts import HttpResponse, render
import psycopg2

# Import db param
from django.conf import settings
db_config = settings.DATABASES["default"]
db_config = {
        'dbname': settings.DATABASES["default"]["NAME"],
        'user': settings.DATABASES["default"]["USER"],
        'password': settings.DATABASES["default"]["PASSWORD"],
        'host': settings.DATABASES["default"]["HOST"],
        'port': settings.DATABASES["default"]["PORT"],
    }

def init(request):
    try:
        # Connect to db
        with psycopg2.connect(**db_config) as conn:
            # Access cursor to perform operations
            with conn.cursor() as cur:
                # Query to create a table
                create_table_query = '''
                CREATE TABLE IF NOT EXISTS ex00_movies (
                    episode_nb INT PRIMARY KEY,
                    title VARCHAR(64) UNIQUE NULL,
                    opening_crawl TEXT,
                    director VARCHAR(32) NOT NULL,
                    producer VARCHAR(128) NOT NULL,
                    release_date DATE NOT NULL
                );
                '''
                # Execute the query
                cur.execute(create_table_query)
                conn.commit() 
                result = b'OK'
    except Exception as e: 
        #Recover error 
        result = str(e).encode('utf-8') 
    return HttpResponse(result)
