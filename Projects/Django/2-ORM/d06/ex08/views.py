from django.shortcuts import render, HttpResponse, HttpResponseRedirect

import psycopg2
from django.conf import settings

def init(request):
    result = ""
    sql_planets = """
                  CREATE TABLE IF NOT EXISTS ex08_planets (
                       id SERIAL PRIMARY KEY,
                       name VARCHAR(64) UNIQUE NOT NULL,
                       climate TEXT,
                       diameter INT,
                       orbital_period INT,
                       population BIGINT,
                       rotation_period INT,
                       surface_water REAL,
                       terrain VARCHAR(128)
                  );
    """
    sql_peoples = """
                  CREATE TABLE IF NOT EXISTS ex08_people (
                        id SERIAL PRIMARY KEY,
                        name VARCHAR(64) UNIQUE NOT NULL,
                        birth_year VARCHAR(32),
                        gender VARCHAR(32),
                        eye_color VARCHAR(32),
                        hair_color VARCHAR(32),
                        height INT,
                        mass REAL,
                        homeworld VARCHAR(64) REFERENCES ex08_planets (name)
                  );
    """
    try:
        with psycopg2.connect(**settings.DB_CONFIG) as conn:
            with conn.cursor() as curs:
                curs.execute(sql_planets)
                curs.execute(sql_peoples)
            conn.commit()
            result = f'<p>OK</p>'
    except Exception as e:
        result = f'<p>Error: {str(e)}</p>'
    return HttpResponse(result.encode('utf-8'), content_type='text/html')

def populate(request):
    result = ""
    try:
        with psycopg2.connect(**settings.DB_CONFIG) as conn:
            with conn.cursor() as curs:
                with open('./exercices_data/planets.csv') as f_planets:
                    curs.copy_from(file=f_planets, table='ex08_planets', null='NULL', sep='\t', columns=('name', 'climate', 'diameter', 'orbital_period', 'population', 'rotation_period', 'surface_water', 'terrain'))
                with open('./exercices_data/people.csv') as f_people:
                    curs.copy_from(file=f_people, table='ex08_people', null='NULL', sep='\t', columns=('name', 'birth_year', 'gender', 'eye_color', 'hair_color', 'height', 'mass', 'homeworld'))
        result = f'<p>OK</p>'
    except Exception as e:
        result = f'<p>Error: {str(e)}</p>'
    return HttpResponse(result.encode('utf-8'), content_type='text/html')

def display(request):
    result = ""
    try:
        with psycopg2.connect(**settings.DB_CONFIG) as conn:
            with conn.cursor() as curs:
                # People name that live in a homeworld with windy climate
                select_query = """
                               SELECT p.name, p.homeworld, pl.climate
                               FROM ex08_people p
                               JOIN ex08_planets pl ON p.homeworld = pl.name
                               WHERE pl.climate ILIKE '%windy%'
                               ORDER BY p.name
                """
                curs.execute(select_query)
                peoples = curs.fetchall()
                colnames = [desc[0] for desc in curs.description]
                # creation of table
                result += '<table border="1">'
                result += '<tr>'
                for colname in colnames:
                    result += f'<td>{colname}</td>'
                result += '</tr>'
                if len(peoples) > 0:
                    for row in peoples:
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

