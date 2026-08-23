-- source .env && watchexec -e sql "docker compose exec -T database psql -U $DB_USER -d $DB_DATABASE -v ON_ERROR_STOP=1 -c '\timing on' -f /dev/stdin < solution.sql"

-- show tables
\dt;

\d tree;

select * from tree;

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

-- Each node in the tree can be one of three types:
--
-- "Leaf": if the node is a leaf node.
-- "Root": if the node is the root of the tree.
-- "Inner": If the node is neither a leaf node nor a root node.
--
--      1
--    /  \
--   2    3
--  / \
-- 4   5
--
--
-- Write a solution to report the type of each node in the tree.
--
-- Return the result table in any order.

select
  t.id,
  case 
    when t.p_id is null then 'Root'
    when exists (select 1 from tree where p_id = t.id) then 'Inner'
    else 'Leaf'
  end as type
from tree t
;
