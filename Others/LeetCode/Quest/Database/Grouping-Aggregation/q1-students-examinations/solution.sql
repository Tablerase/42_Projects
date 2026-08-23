-- source .env && watchexec -e sql "docker compose exec -T database psql -U $DB_USER -d $DB_DATABASE -v ON_ERROR_STOP=1 -c '\timing on' -f /dev/stdin < solution.sql"

-- show tables
\dt;

\d examinations;
\d students;
\d subjects;

select * from examinations;
select * from students;
select * from subjects;

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

-- Write a solution to find the number of times each student attended each exam.
--
-- Return the result table ordered by student_id and subject_name.
--
-- The result format is in the following example.

select
  t.student_id,
  t.student_name,
  s.subject_name,
  count(e.student_id) as attended_exams
from
  students t
cross join
  subjects s
left join
  examinations e on e.student_id = t.student_id and s.subject_name = e.subject_name
group by
  s.subject_name, t.student_id, t.student_name
order by
  t.student_id ASC, s.subject_name ASC
;
