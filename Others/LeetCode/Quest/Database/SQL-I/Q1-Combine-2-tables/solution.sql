-- show tables
\dt;

\d person;

\d address;

-- query content
select * from address;
select * from person;

-- Write a solution to report the first name, last name, 
-- city, and state of each person in the Person table.
-- If the address of a personId is not present in the Address table, report null instead.
--
-- JOIN Type                      │ Behavior                                                                   │ What happens if no match?
-- ───────────────────────────────┼────────────────────────────────────────────────────────────────────────────┼─────────────────────────────────────────
--  INNER JOIN                    │ Keeps only rows that exist in BOTH tables.                                 │ Rows with no match are dropped/excluded.
--  LEFT JOIN (or LEFT OUTER JOIN)│ Keeps ALL rows from the left table, and matches what it can from the right.│ Missing right-table values become NULL.
--  RIGHT JOIN                    │ Keeps ALL rows from the right table, and matches what it can from the left.│ Missing left-table values become NULL.
--  FULL OUTER JOIN               │ Keeps ALL rows from both tables.                                           │ Any missing side becomes NULL.

select p.firstname, p.lastname, a.city, a.state
  from person as p
  left join address as a
  on p.personid = a.personid;

