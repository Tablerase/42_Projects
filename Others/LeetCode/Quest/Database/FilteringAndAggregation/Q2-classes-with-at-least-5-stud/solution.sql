-- show tables
\dt;

\d courses;

SELECT * FROM courses;

-- Convention
--  • SQL Keywords in UPPERCASE: SELECT, FROM, WHERE, GROUP BY, JOIN, ON, COUNT
--  • Table & Column Names in lowercase_snake_case: customer_number, orders, id

-- JOIN Type                      │ Behavior                                                                   │ What happens if no match?
-- ───────────────────────────────┼────────────────────────────────────────────────────────────────────────────┼─────────────────────────────────────────
--  INNER JOIN                    │ Keeps only rows that exist in BOTH tables.                                 │ Rows with no match are dropped/excluded.
--  LEFT JOIN (or LEFT OUTER JOIN)│ Keeps ALL rows from the left table, and matches what it can from the right.│ Missing right-table values become NULL.
--  RIGHT JOIN                    │ Keeps ALL rows from the right table, and matches what it can from the left.│ Missing left-table values become NULL.
--  FULL OUTER JOIN               │ Keeps ALL rows from both tables.                                           │ Any missing side becomes NULL.

-- Write a solution to find all the classes that have at least five students.
--
-- Return the result table in any order.

SELECT c.class 
  FROM courses AS c
  GROUP BY c.class
  HAVING COUNT(*) >= 5
;
