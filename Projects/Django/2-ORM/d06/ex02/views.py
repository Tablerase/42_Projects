from django.shortcuts import HttpResponse
import psycopg2

# Import db param
from django.conf import settings

def init(request):
    try:
        # Connect to db
        with psycopg2.connect(**settings.DB_CONFIG) as conn:
            # Access cursor to perform operations
            with conn.cursor() as cur:
                # Query to create a table
                create_table_query = '''
                CREATE TABLE IF NOT EXISTS ex02_movies (
                    episode_nb INT PRIMARY KEY,
                    title VARCHAR(64) UNIQUE NOT NULL,
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

def populate(request):
    result = b''
    try:
        with psycopg2.connect(**settings.DB_CONFIG) as conn:
            with conn.cursor() as cur:
                insert_query = """
                INSERT INTO ex02_movies (episode_nb, title, director, producer, release_date)
                VALUES (%s,%s,%s,%s,%s)
                """
                records = [
            (1, 'The Phantom Menace', 'George Lucas', 'Rick McCallum', '1999-05-19'),
            (2, 'Attack of the Clones', 'George Lucas', 'Rick McCallum', '2002-05-16'),
            (3, 'Revenge of the Sith', 'George Lucas', 'Rick McCallum', '2005-05-19'),
            (4, 'A New Hope', 'George Lucas', 'Gary Kurtz, Rick McCallum', '1977-05-25'),
            (5, 'The Empire Strikes Back', 'Irvin Kershner', 'Gary Kurtz, Rick McCallum', '1980-05-17'),
            (6, 'Return of the Jedi', 'Richard Marquand', 'Howard G. Kazanjian, George Lucas, Rick McCallum', '1983-05-25'),
            (7, 'The Force Awakens', 'J. J. Abrams', 'Kathleen Kennedy, J. J. Abrams, Bryan Burk', '2015-12-11')
                ]
                for record in records:
                    cur.execute(insert_query, record)
                    result += b'OK\n'
                conn.commit()
    except Exception as e: 
        #Recover error 
        result = str(e).encode('utf-8') 
    return HttpResponse(result)

def display(request):
    result = ''
    try:
        with psycopg2.connect(**settings.DB_CONFIG) as conn:
            with conn.cursor() as cur:
                select_query = """
                SELECT * FROM ex02_movies
                """
                cur.execute(select_query)
                # result of sql query
                rows = cur.fetchall()
                colnames = [desc[0] for desc in cur.description]

                # creation of table
                result += '<table border="1">'
                result += '<tr>'
                for colname in colnames:
                    result += f'<td>{colname}</td>'
                result += '</tr>'
                if len(rows) > 0:
                    for row in rows:
                        result += '<tr>'
                        for cell in row:
                            result += f'<td>{cell}</td>'
                        result += '</tr>'
                    result += '</table>'
                else:
                    raise ValueError

    except Exception as e: 
        #Recover error 
        # result = f'<p>Error: {str(e)}</p>'
        result = '<p>No data available</p>'
    return HttpResponse(result.encode('utf-8'), content_type='text/html')

