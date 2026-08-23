-- source .env && watchexec -e sql "docker compose exec -T database psql -U $DB_USER -d $DB_DATABASE -v ON_ERROR_STOP=1 -c '\timing on' -f /dev/stdin < solution.sql"

-- show tables
\dt;

\d activity;

SELECT * FROM activity;

-- Convention
--  • SQL Keywords in UPPERCASE: SELECT, FROM, WHERE, GROUP BY, JOIN, ON, COUNT
--  • Table & Column Names in lowercase_snake_case: customer_number, orders, id

-- JOIN Type                      │ Behavior                                                                   │ What happens if no match?
-- ───────────────────────────────┼────────────────────────────────────────────────────────────────────────────┼─────────────────────────────────────────
--  INNER JOIN                    │ Keeps only rows that exist in BOTH tables.                                 │ Rows with no match are dropped/excluded.
--  LEFT JOIN (or LEFT OUTER JOIN)│ Keeps ALL rows from the left table, and matches what it can from the right.│ Missing right-table values become NULL.
--  RIGHT JOIN                    │ Keeps ALL rows from the right table, and matches what it can from the left.│ Missing left-table values become NULL.
--  FULL OUTER JOIN               │ Keeps ALL rows from both tables.                                           │ Any missing side becomes NULL.

-- NOT in postgres:
-- FLOAT(2, 3) -> use NUMERICAL(precision,scale)
-- inline ENUM -> CREATE TYPE ... AS ENUM before using in schema

-- Write a solution to find the daily active user count for a period of 30 days ending 2019-07-27 inclusively. 
-- A user was active on someday if they made at least one activity on that day.
--
-- Return the result table in any order.
--
-- The result format is in the following example.
--
-- Note: Any activity from ('open_session', 'end_session', 'scroll_down', 'send_message') will be considered valid activity 
-- for a user to be considered active on a day.

create index if not exists idx_activity_date_user on activity (activity_date, user_id);

select 
  activity_date as day,
  count(distinct user_id) as active_users
from activity 
where activity_date <= '2019-07-27' and activity_date > '2019-06-27'
group by activity_date
;
