from django.shortcuts import render, HttpResponse, HttpResponseRedirect

import psycopg2
from django.conf import settings

from .forms import Update_crawl

# Create your views here.
def init(request):
    result = ""

    # Create a TABLE
    ## Set created column value at creation of each ROW
    ### Update row 'updated' column to current time when a row is UPDATE
    sql_query = """
                CREATE TABLE IF NOT EXISTS ex06_movies (
                    episode_nb INT PRIMARY KEY,
                    title VARCHAR(64) UNIQUE NULL,
                    opening_crawl TEXT,
                    director VARCHAR(32) NOT NULL,
                    producer VARCHAR(128) NOT NULL,
                    release_date DATE NOT NULL,
                    created TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,
                    updated TIMESTAMP
                );

                CREATE OR REPLACE FUNCTION update_changetimestamp_column()
                RETURNS TRIGGER AS $$
                BEGIN
                    NEW.updated = now();
                    NEW.created = OLD.created;
                    RETURN NEW;
                END;
                $$ language 'plpgsql';

                CREATE TRIGGER update_films_changetimestamp BEFORE UPDATE
                ON ex06_movies FOR EACH ROW EXECUTE PROCEDURE
                update_changetimestamp_column();
    """
    try:
        with psycopg2.connect(**settings.DB_CONFIG) as conn:
            with conn.cursor() as curs:
                curs.execute(sql_query)
            conn.commit()
            result = f'<p>OK</p>'
    except Exception as e:
        result = f'<p>Error: {str(e)}</p>'
    return HttpResponse(result.encode('utf-8'), content_type='text/html')

def populate(request):
    result = ''
    try:
        with psycopg2.connect(**settings.DB_CONFIG) as conn:
            with conn.cursor() as cur:
                insert_query = """
                INSERT INTO ex06_movies (episode_nb, title, director, producer, release_date)
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
                SELECT * FROM ex06_movies
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

def update(request):
    try:
        with psycopg2.connect(**settings.DB_CONFIG) as conn:
            with conn.cursor() as curs:
                # double title because form need a tuple with key, value
                curs.execute("SELECT title, title FROM ex06_movies ORDER BY episode_nb")
                titles = curs.fetchall()
    except Exception:
        titles = []
    if request.method == 'POST':
        form = Update_crawl(titles, request.POST)
        if form.is_valid():
            to_update = form.cleaned_data['title']
            new_opening_crawl = form.cleaned_data['opening_crawl']
            try:
                with psycopg2.connect(**settings.DB_CONFIG) as conn:
                    with conn.cursor() as curs:
                        curs.execute("UPDATE ex06_movies SET opening_crawl = %s WHERE title = %s", (new_opening_crawl, to_update, ))
                    conn.commit()
            except Exception:
                result = '<p>No data available</p>'
                return HttpResponse(result.encode('utf-8'), content_type='text/html')
        return HttpResponseRedirect('update')
    else:
        form = Update_crawl(titles=titles)
        context = {
                'form' : form
                }
        return render(request, 'update_form.html', context)

