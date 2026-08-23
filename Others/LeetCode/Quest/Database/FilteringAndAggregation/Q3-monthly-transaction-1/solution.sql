-- show tables
\dt;

\d transactions;

SELECT * FROM transactions;

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

-- Write an SQL query to find for each month and country, the number of transactions and their total amount,
-- the number of approved transactions and their total amount.
--
-- Return the result table in any order.

SELECT 
  to_char(t.trans_date, 'YYYY-MM') as month,
  t.country as country,
  COUNT(t.id) as trans_count,
  COUNT(
    CASE
        WHEN t.state = 'approved' THEN 1
    END
    ) as approved_count,
  SUM(t.amount) as trans_total_amount,
  SUM(
    CASE 
    WHEN t.state = 'approved' THEN t.amount ELSE 0
    END
  ) as approved_total_amount
FROM transactions t
GROUP BY
  t.country,
  month
ORDER BY
  month ASC
;
