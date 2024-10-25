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
                with open('../../exercices_data/planets.csv') as f_planets:
                    curs.copy_from(file=f_planets, table='ex08_planets', sep='\t', columns=('name', 'other columns'))
                    ....







