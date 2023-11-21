# Get Next Line

## Static variable

Static variables have the property of preserving their value even after they are out of their scope. This means that a static variable retains its previous value in its previous scope and is not initialized again in the new scope.

Static variables are allocated within the data segment of the program instead of the C stack. Memory for a static variable is allocated once and remains throughout the program. A static variable persists, even after the end of a function or block

Exemple:

```c
#include <stdio.h>

void countCalls(void);

int main()
{
  countCalls();
  countCalls();
  countCalls();

  return 0;
}

void countCalls(void)
{
  static int count = 0;  // static variable

  count++;
  printf("Function has been called %d times\n", count);
}
```

Static variables can also be declared globally

```c
#include <stdio.h>

static int count = 0;  // global static variable

void countCalls(void);

int main()
{
  countCalls();
  countCalls();
  countCalls();

  return 0;
}

void countCalls(void)
{
  count++;
  printf("Function has been called %d times\n", count);
}

```

The syntax to declare a static variable in C is as follows:

```c
static data_type variable_name;
```

Static variables are initialized with a default value, either 0 or NULL. If not initialized explicitly, static variables are initialized as 0

## Requierements

- Makefile (with at least: rules $(NAME), all, clean, fclean and re).
- Bonus add a rule bonus and use different *_bonus.h,*_bonus.c

## Mandatory

RETURN:

- If read -> return the line that was read
  - return should include `\n` and even if no `\n` at the end of the file.
- If error or nothing to read -> return `NULL`.

FUNCTION:

- Description:
  - Write a function that returns a line read from a
file descriptor
- Should work properly when reading file or standard input
- All helper functions in get_next_line_utils.c

Undefined Behaviour:

- If file change between call
- Read of binary file. U can do handle if you want but it's not required.

Forbidden:

- lseek() is forbidden.
- Global variables are forbidden

## To TEST

- [Tripouille testeur](https://github.com/Tripouille/gnlTester)

- Fill a file.txt with some text. And call them with the function.
