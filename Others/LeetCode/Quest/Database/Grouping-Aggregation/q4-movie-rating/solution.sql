-- source .env && watchexec -e sql "docker compose exec -T database psql -U $DB_USER -d $DB_DATABASE -v ON_ERROR_STOP=1 -c '\timing on' -f /dev/stdin < solution.sql"

-- show tables
\dt;

\d movierating;
\d movies;
\d users;

select * from movierating;
select * from movies;
select * from users;

-- Convention
--  • SQL Keywords in UPPERCASE: SELECT, FROM, WHERE, GROUP BY, JOIN, ON, COUNT
--  • Table & Column Names in lowercase_snake_case: customer_number, orders, id

-- JOIN Type                      │ Behavior                                                                   │ What happens if no match?
-- ───────────────────────────────┼────────────────────────────────────────────────────────────────────────────┼─────────────────────────────────────────
--  INNER JOIN (default)          │ Keeps only rows that exist in BOTH tables.                                 │ Rows with no match are dropped/excluded.
--  LEFT JOIN (or LEFT OUTER JOIN)│ Keeps ALL rows from the left table, and matches what it can from the right.│ Missing right-table values become NULL.
--  RIGHT JOIN                    │ Keeps ALL rows from the right table, and matches what it can from the left.│ Missing left-table values become NULL.
--  FULL OUTER JOIN               │ Keeps ALL rows from both tables.                                           │ Any missing side becomes NULL.
--  CROSS JOIN                    │ Cartesian Product                                                          │ Multiplies every row of A with every row of B.

-- NOT in postgres:
-- FLOAT(2, 3) -> use NUMERICAL(precision,scale)
-- inline ENUM -> CREATE TYPE ... AS ENUM before using in schema

-- CTE (Reads top-to-bottom like regular code):
--     WITH
--         Step1 AS (SELECT ...),
--         Step2 AS (SELECT ... FROM Step1),
--         Step3 AS (SELECT ... FROM Step2)
--     SELECT * FROM Step3;

-- Write a solution to:
--
-- Find the name of the user who has rated the greatest number of movies. In case of a tie, return the lexicographically smaller user name.
-- Find the movie name with the highest average rating in February 2020. In case of a tie, return the lexicographically smaller movie name.

select
  *
from
  users u
join
  movierating mv on mv.user_id = u.user_id
join
  movies m on m.movie_id = mv.movie_id
;

(
  -- name of user + number of ratings
  select
    u.name as results
  from users u
  join movierating mv on mv.user_id = u.user_id
  group by u.name
  order by
    count(u.name) DESC, u.name ASC
  limit 1
)
union all
(
  -- movie highest rating average in feb 2020
  select
    m.title as results
  from movierating mv
  join movies m on m.movie_id = mv.movie_id
  where mv.created_at >= '2020-02-01' and mv.created_at < '2020-03-01'
  group by m.title
  order by
    avg(mv.rating) DESC, m.title ASC
  limit 1
);
