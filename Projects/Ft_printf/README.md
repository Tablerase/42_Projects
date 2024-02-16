# Printf

## Requirements

Program name: `libftprintf.a`

Turn in files: `Makefile, *.h, */*.h, *.c, */*.c`

Makefile: `NAME, all, clean, fclean, re`

External functs: `malloc, free, write,
va_start, va_arg, va_copy, va_end`

Libft authorized: Yes

Description: Write a library that contains ft_printf(), a function that will mimic the original printf()

Here are the requirements:

- Don’t implement the buffer management of the original printf().
- Your function has to handle the following conversions: `cspdiuxX%`
- Your function will be compared against the original printf().
- You must use the command ar to create your library.
Using the libtool command is forbidden.
- Your libftprintf.a has to be created at the root of your repository.

You have to implement the following conversions:

- `%c` Prints a single character.
- `%s` Prints a string (as defined by the common C convention).
- `%p` The void * pointer argument has to be printed in hexadecimal format.
- `%d` Prints a decimal (base 10) number.
- `%i` Prints an integer in base 10.
- `%u` Prints an unsigned decimal (base 10) number.
- `%x` Prints a number in hexadecimal (base 16) lowercase format.
- `%X` Prints a number in hexadecimal (base 16) uppercase format.
- `%%` Prints a percent sign.

Printf: 🔗 [Details](https://learn.microsoft.com/fr-fr/cpp/c-runtime-library/format-specification-syntax-printf-and-wprintf-functions?view=msvc-170)

Limits:

- Long long:
  - max : `9,223,372,036,854,775,807`, Len 19 char
  - binary long long max: `0111111111111111111111111111111111111111111111111111111111111111`, Len: 64 char

- Unsigned int max = `4294967295`
- Int max = `2147483647`;
- Int min = `-2147483648`;

## Variadic Functions

header: `#include <stdarg.h>`

Variadic function adds flexibility to the program. It takes one fixed argument and then any number of arguments can be passed. The variadic function consists of **at least one fixed variable** and then an **ellipsis(…)** as the last parameter.

Syntax: `int function_name(data_type variable_name, ...);`

Create a **va_list** with: `va_list name_of_list;`

To use / iterate on the list:

- va_start(name_of_list, variable_name)

- va_end(name_of_list)

Methods | Description
------- | ----------
`va_start(va_list ap, argN)` | This enables access to variadic function arguments. Where *va_list* will be the pointer to the last fixed argument in the variadic function. *argN* is the last fixed argument in the variadic function. From the above variadic function (function_name (data_type variable_name, …); ), variable_name is the last fixed argument making it the argN. Whereas *va_list ap* will be a pointer to argN (variable_name)
`va_arg(va_list ap, type)` | This one accesses the next variadic function argument. *va_list ap* is the same as above i.e a pointer to argN. *type* indicates the data type  the *va_list ap* should expect (double, float, int etc.)
`va_copy(va_list dest, va_list src)` | This makes a copy of the variadic function arguments.
`va_end(va_list ap)` | This ends the traversal of the variadic function arguments.

Example:

```c
// C program for the above approach

#include <stdarg.h>
#include <stdio.h>

// Variadic function to add numbers
int AddNumbers(int n, ...)
{
 int Sum = 0;

 // Declaring pointer to the
 // argument list
 va_list ptr;

 // Initializing argument to the
 // list pointer
 va_start(ptr, n);

 for (int i = 0; i < n; i++)

  // Accessing current variable
  // and pointing to next one
  Sum += va_arg(ptr, int);

 // Ending argument list traversal
 va_end(ptr);

 return Sum;
}

// Driver Code
int main()
{
 printf("\n\n Variadic functions: \n");

 // Variable number of arguments
 printf("\n 1 + 2 = %d ",
  AddNumbers(2, 1, 2));

 printf("\n 3 + 4 + 5 = %d ",
  AddNumbers(3, 3, 4, 5));

 printf("\n 6 + 7 + 8 + 9 = %d ",
  AddNumbers(4, 6, 7, 8, 9));

 printf("\n");

 return 0;
}
```

```output
Variadic functions: 

 1 + 2 = 3 
 3 + 4 + 5 = 12 
 6 + 7 + 8 + 9 = 30
```

🔗 [Details](https://www.geeksforgeeks.org/variadic-functions-in-c/)