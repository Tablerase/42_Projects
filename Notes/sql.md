# SQL

SQL (Structured Query Language) is a standard language for storing, manipulating and retrieving data in databases. 

The scope of SQL includes data query, data manipulation (insert, update, and delete), data definition (schema creation and modification), and data access control. Although SQL is essentially a declarative language, it also includes procedural elements.

## SQL Syntax

SQL syntax is the set of rules that define how SQL statements are written and interpreted. The basic syntax of an SQL statement is:

```sql
SELECT column1, column2, ...
FROM table_name
WHERE condition
GROUP BY column
HAVING condition
ORDER BY column
LIMIT number;
```

### SQL Keywords

SQL keywords are reserved words that are used to perform operations such as selecting, updating, deleting, or inserting data. Keywords cannot be used as identifiers.

### SQL Identifiers

Identifiers are names of tables, columns, databases, and other database objects. Identifiers must follow certain rules:

- Identifiers must start with a letter or an underscore.
- Identifiers can contain letters, digits, and underscores.
- Identifiers cannot be a keyword.
- Identifiers cannot contain spaces.
- Identifiers are case-insensitive.

### SQL Comments

SQL comments are used to explain SQL code and are ignored by the database. There are two types of SQL comments:

- Single-line comments: Begin with `--` and end at the end of the line.
- Multi-line comments: Begin with `/*` and end with `*/`.

### SQL Statements

SQL statements are used to perform operations on a database. The most common SQL statements are:

- `SELECT`: Retrieves data from one or more tables.
- `INSERT`: Adds new rows to a table.
- `UPDATE`: Modifies existing rows in a table.
- `DELETE`: Removes rows from a table.
- `CREATE`: Creates a new table, view, or index.
- `ALTER`: Modifies an existing table or view.
- `DROP`: Deletes a table, view, or index.

### SQL Clauses

SQL clauses are used to filter, group, and sort data. The most common SQL clauses are:

- `WHERE`: Filters rows based on a condition.
- `GROUP BY`: Groups rows based on a column.
- `HAVING`: Filters groups based on a condition.
- `ORDER BY`: Sorts rows based on one or more columns.
- `LIMIT`: Limits the number of rows returned.

### SQL Operators

SQL operators are used to perform operations on data. The most common SQL operators are:

- Arithmetic operators: `+`, `-`, `*`, `/`.
- Comparison operators: `=`, `!=`, `<`, `>`, `<=`, `>=`.
- Logical operators: `AND`, `OR`, `NOT`.
- String operators: `||` (concatenation), `LIKE`, `IN`.

### SQL Functions

SQL functions are built-in functions that perform operations on data. The most common SQL functions are:

- Aggregate functions: `COUNT`, `SUM`, `AVG`, `MIN`, `MAX`.
- Scalar functions: `UPPER`, `LOWER`, `SUBSTR`, `TRIM`.
- Date functions: `CURRENT_DATE`, `CURRENT_TIME`, `CURRENT_TIMESTAMP`.

## SQL Data Types

SQL data types specify the type of data that can be stored in a column of a table. The most common SQL data types are:

- Numeric data types: `INT`, `FLOAT`, `DECIMAL`.
- Character data types: `CHAR`, `VARCHAR`, `TEXT`.
- Date and time data types: `DATE`, `TIME`, `TIMESTAMP`.
- Boolean data type: `BOOLEAN`.
- Binary data types: `BLOB`, `CLOB`.

## SQL Constraints

SQL constraints are rules that enforce data integrity in a database. The most common SQL constraints are:

- `NOT NULL`: Ensures that a column cannot contain `NULL` values.
- `UNIQUE`: Ensures that all values in a column are unique.
- `PRIMARY KEY`: Combines `NOT NULL` and `UNIQUE` constraints to create a unique identifier for a row.
- `FOREIGN KEY`: Ensures that values in a column match values in another table.
- `CHECK`: Ensures that values in a column meet a specific condition.

## SQL Joins

SQL joins are used to combine rows from two or more tables based on a related column between them. The most common SQL joins are:

- `INNER JOIN`: Returns rows when there is a match in both tables.
- `LEFT JOIN`: Returns all rows from the left table and the matched rows from the right table.
- `RIGHT JOIN`: Returns all rows from the right table and the matched rows from the left table.
- `FULL JOIN`: Returns rows when there is a match in one of the tables.

<img src="https://i.stack.imgur.com/UI25E.jpg" alt="SQL Joins">
