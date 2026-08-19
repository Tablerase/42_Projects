-- show tables
\dt;

\d cinema;

select * from cinema;

-- JOIN Type                      │ Behavior                                                                   │ What happens if no match?
-- ───────────────────────────────┼────────────────────────────────────────────────────────────────────────────┼─────────────────────────────────────────
--  INNER JOIN                    │ Keeps only rows that exist in BOTH tables.                                 │ Rows with no match are dropped/excluded.
--  LEFT JOIN (or LEFT OUTER JOIN)│ Keeps ALL rows from the left table, and matches what it can from the right.│ Missing right-table values become NULL.
--  RIGHT JOIN                    │ Keeps ALL rows from the right table, and matches what it can from the left.│ Missing left-table values become NULL.
--  FULL OUTER JOIN               │ Keeps ALL rows from both tables.                                           │ Any missing side becomes NULL.
--
-- ────────────────────────────────────────────────────────────────────────────
--  In SQL numerical types like NUMERIC(p, s or DECIMAL(p, s):
--
-- • p (Precision) = Total number of digits (both before and after the decimal point).
-- • s (Scale) = Number of digits after the decimal point (the decimal places).
  --     ┌─── Total digits (p) = 5 ───┐
  --
  --     [ 1 ] [ 2 ] [ 3 ] . [ 4 ] [ 5 ]
  --     └───────────────┘   └─────────┘
  --      3 digits before     2 digits after
  --        the decimal         the decimal (s = 2)
  --
  -- • Total digits (p): 5
  -- • Decimals (s): 2
  -- • Digits before decimal (p - s): 5 - 2 = 3
  -- • Range allowed: -999.99 to +999.99

-- Write a solution to report the movies with an odd-numbered ID and a description that is not "boring".
--
-- Return the result table ordered by rating in descending order.

select c.id, c.movie, c.description, c.rating
  from cinema as c
  where 
    c.description != 'boring'
    and (c.id % 2) = 1 
  order by c.rating desc;

