from django.shortcuts import HttpResponse, HttpResponseRedirect, render
import psycopg2

# Import db param
from django.conf import settings

# import forms
from .forms import Remove_Title

def init(request):
    try:
        # Connect to db
        with psycopg2.connect(**settings.DB_CONFIG) as conn:
            # Access cursor to perform operations
            with conn.cursor() as cur:
                # Query to create a table
                create_table_query = '''
                CREATE TABLE IF NOT EXISTS ex04_movies (
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
    result = ''
    try:
        with psycopg2.connect(**settings.DB_CONFIG) as conn:
            with conn.cursor() as cur:
                insert_query = """
                INSERT INTO ex04_movies (episode_nb, title, director, producer, release_date)
                VALUES (%s,%s,%s,%s,%s)
                ON CONFLICT DO NOTHING
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
                    try :
                        cur.execute(insert_query, record)
                        # Check if the row was inserted
                        if cur.rowcount > 0:
                            result += f'<p>OK: <strong>{record[1]}</strong></p>\n'
                        else:
                            result += f'<p><strong>{record[1]}</strong> already exists</p>\n'
                    except psycopg2.Error as e:
                    # except Exception as e: 
                        result += f'<p>Error: {str(e)}</p>\n'
                        continue
                        # pass
                conn.commit()
    except Exception as e: 
        #Recover error 
        result = f'<p>Error: {str(e)}</p>'
    return HttpResponse(result.encode('utf-8'), content_type='text/html')

def display(request):
    result = ''
    try:
        with psycopg2.connect(**settings.DB_CONFIG) as conn:
            with conn.cursor() as cur:
                select_query = """
                SELECT * FROM ex04_movies
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

def remove(request):
    try:
        with psycopg2.connect(**settings.DB_CONFIG) as conn:
            with conn.cursor() as curs:
                # double title because form need a tuple with key, value
                curs.execute("SELECT title, title FROM ex04_movies ORDER BY episode_nb")
                titles = curs.fetchall()
    except Exception:
        titles = []
    if request.method == 'POST':
        form = Remove_Title(titles, request.POST)
        if form.is_valid():
            to_rm = form.cleaned_data['title']
            try:
                with psycopg2.connect(**settings.DB_CONFIG) as conn:
                    with conn.cursor() as curs:
                        curs.execute("DELETE FROM ex04_movies WHERE title = %s", (to_rm, ))
                    conn.commit()
            except Exception:
                result = '<p>No data available</p>'
                return HttpResponse(result.encode('utf-8'), content_type='text/html')
        return HttpResponseRedirect('remove')
    else:
        form = Remove_Title(titles=titles)
        context = {
                'form' : form
                }
        return render(request, 'remove_form.html', context)

