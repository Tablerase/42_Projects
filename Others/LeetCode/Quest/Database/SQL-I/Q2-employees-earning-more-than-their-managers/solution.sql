-- show tables
\dt;

\d employee;

select * from employee;

-- JOIN Type                      │ Behavior                                                                   │ What happens if no match?
-- ───────────────────────────────┼────────────────────────────────────────────────────────────────────────────┼─────────────────────────────────────────
--  INNER JOIN                    │ Keeps only rows that exist in BOTH tables.                                 │ Rows with no match are dropped/excluded.
--  LEFT JOIN (or LEFT OUTER JOIN)│ Keeps ALL rows from the left table, and matches what it can from the right.│ Missing right-table values become NULL.
--  RIGHT JOIN                    │ Keeps ALL rows from the right table, and matches what it can from the left.│ Missing left-table values become NULL.
--  FULL OUTER JOIN               │ Keeps ALL rows from both tables.                                           │ Any missing side becomes NULL.

-- Write a solution to find the employees who earn more than their managers.

with managers as (
  select * from employee as e
  where e.managerid is null
)
select * from managers;

select e.name as "Employee"
  from employee as e
  join employee as m
  on e.managerid = m.id
  where m.salary < e.salary
  ;
