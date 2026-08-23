-- source .env && watchexec -e sql "docker compose exec -T database psql -U $DB_USER -d $DB_DATABASE -v ON_ERROR_STOP=1 -c '\timing on' -f /dev/stdin < solution.sql"

-- show tables
\dt;

\d customer;
\d product;

select * from customer;
select * from product;

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

-- Write a solution to report the customer ids from the Customer table that bought all the products in the Product table.
--
-- Return the result table in any order.
insert into customer(customer_id, product_key) values (1, 5);

select 
  c.customer_id
from 
  customer c
group by
  c.customer_id
having
  count(distinct c.product_key) = (select count(*) from product)
;

