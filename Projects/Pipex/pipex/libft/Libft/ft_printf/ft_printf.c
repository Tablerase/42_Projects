/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:09:33 by rcutte            #+#    #+#             */
/*   Updated: 2023/12/08 12:22:42 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
Program name: `libftprintf.a`

Turn in files: Makefile, *.h, *.c

Makefile: `NAME, all, clean, fclean, re`

External functs: `malloc, free, write,
va_start, va_arg, va_copy, va_end`

Return value: Number of char printed 

Libft authorized: Yes

Description: Write a library that contains ft_printf(), 
a function that will mimic the original printf()

- %c Prints a single character.
- %s Prints a string (as defined by the common C convention).
- %p The void * pointer argument has to be printed in hexadecimal format.
- %d Prints a decimal (base 10) number.
- %i Prints an integer in base 10.
- %u Prints an unsigned decimal (base 10) number.
- %x Prints a number in hexadecimal (base 16) lowercase format.
- %X Prints a number in hexadecimal (base 16) uppercase format.
- %% Prints a percent sign.
*/

#include "../../Includes/libft.h"
#include "../../Includes/ft_printf.h"

/*
Max long long: 9223372036854775807
- Len 19 char
- Binary Len: 64 char, Use for reusability in other case
*/
static int	ft_print_num(long long num, char type)
{
	int		printed;
	char	*str;

	printed = 0;
	str = ft_calloc(64 + 1, sizeof(char));
	if (!str)
		return (printed);
	if (type == 'i')
		ft_putnbr_base(num, "0123456789", str);
	if (type == 'u')
		ft_putnbr_base(num, "0123456789", str);
	if (type == 'x')
		ft_putnbr_base(num, "0123456789abcdef", str);
	if (type == 'X')
		ft_putnbr_base(num, "0123456789ABCDEF", str);
	if (num < 0)
	{
		printed += write(1, "-", 1);
		printed += ft_reverse_print_str(str + 1);
	}
	else
		printed += ft_reverse_print_str(str);
	free(str);
	return (printed);
}

// print address
// allocation: size of max long long len: 7FFFFFFFFFFFFFFF -> 17 char 
static int	ft_print_address(unsigned long long address)
{
	char				*str;
	int					printed;

	printed = 0;
	if (!address)
	{
		printed += write(1, "(nil)", 5);
		return (printed);
	}
	str = ft_calloc(17 + 1, sizeof(char));
	ft_uputnbr_base(address, "0123456789abcdef", str);
	printed += write(1, "0x", 2);
	printed += ft_reverse_print_str(str);
	free(str);
	return (printed);
}

//check parse of % end return the type as a char.
// %x only search if x is a wanted tags.
// tags: cspdiuxX%
static int	ft_print_type(va_list argument, char c)
{
	int	result;

	result = 0;
	if (c == 'c')
		result += ft_print_char((char)va_arg(argument, int));
	if (c == 's')
		result += ft_print_str(va_arg(argument, char *));
	if (c == '%')
		result += write(1, "%", 1);
	if (c == 'i' || c == 'd')
		result += ft_print_num(va_arg(argument, int), 'i');
	if (c == 'u')
		result += ft_print_num(va_arg(argument, unsigned int), 'u');
	if (c == 'x')
		result += ft_print_num(va_arg(argument, unsigned int), 'x');
	if (c == 'X')
		result += ft_print_num(va_arg(argument, unsigned int), 'X');
	if (c == 'p')
		result += ft_print_address(va_arg(argument, unsigned long long));
	return (result);
}

int	ft_printf(const char *format, ...)
{
	int		count_print;
	va_list	args_ptr;
	char	*read;

	count_print = 0;
	if (!format)
		return (-1);
	va_start(args_ptr, format);
	read = (char *)format;
	while (*read)
	{
		if (*read == '%' && *(read + 1) != '\0')
		{
			count_print += ft_print_type(args_ptr,*(read + 1));
			read += 2;
		}
		else if (*read == '%' && *(read + 1) == '\0')
			return (va_end(args_ptr), -1);
		else
		{
			count_print += ft_print_char(*read);
			read++;
		}
	}
	return (va_end(args_ptr), count_print);
}
/* 
#include <stdio.h>
#include <limits.h>

int	main()
{
	// printf(" %p %p ", LONG_MIN, LONG_MAX);
	// printf(" %p %p ", ULONG_MAX, -ULONG_MAX);
	// printf(" %p %p ", 0, 0);
	// printf("\n");
	// ft_printf(" %p %p ", LONG_MIN, LONG_MAX);
	// // long min and u long max not handle
	// ft_printf(" %p %p ", ULONG_MAX, -ULONG_MAX);
	// ft_printf(" %p %p ", 0, 0);
	
	// char	*s = "TEST";
	// int a = ft_printf("Test %i, %d\nTest char: %c, %s\nTest Address %p", 
	// 42, -42, 'c', s, s);
	// printf("\n");
	// int b = printf("Test %i, %d\nTest char: %c, %s\nTest Address %p",
	// 42, -42, 'c', s, s);
	// printf("\n%i | %i", a, b);

	// // Test basic
	// char c = 'A';
	// int a = ft_printf("%c", c);
	// printf("\n%i | expected: %c\n", a, c);
	// char *str = "String";
	// a = ft_printf("%s", str);
	// printf("\n%i | expected: %s\n", a, str);
	// a = ft_printf("%%");
	// printf("\n%i | expected: %%\n", a);
	// //int int_max = 2147483647;
	// int	int_min = -2147483648;
	// a = ft_printf("%i", int_min);
	// printf("\n%i | expected: %i\n", a, int_min);
	// unsigned int umax = 4294967295;
	// a = ft_printf("%u", umax);
	// printf("\n%i | expected: %u\n", a, umax);
	// a = ft_printf("%x", umax);
	// printf("\n%i | expected: %x\n", a, umax);
	// a = ft_printf("%X", umax);
	// printf("\n%i | expected: %X\n", a, umax);
	// a = ft_printf("%p", str);
	// printf("\n%i | expected: %p\n", a, str);
	
	// Test %i with invalid input (compil without error flags)
	// ft_printf("%i", 563543543434434434); // Output: -236988542
	// printf("%i", 563543543434434434);    // Output: -236988542

	//printf("%s: %%\n", "%%");
	// Output: %%: %
	//printf("%i", 42); printf(" | %d\n", 42);
	// Output: 42 | 42
	//printf("%c\n", '5');
	// Output: 5
	// char	*s = NULL;
	// char	*s2 = "Test";
	// printf("%p %p %s\n", s, s2, s2);
	// Output: (nil) 0x561bd3d5f01d Test
	//printf("Test: %i", ft_isalnum('c'));
} 
 */

/* // ! Test to delimite printf return and conditions
#include <stdio.h>
int	main()
{
	// TODO: Below test cant compile with tags if just informative
	printf("Test: %s\n"); 
	// print a garbage value string. Output: Test: w����
	printf("Test: %s\n", "test", "test2"); 
	// print the first va_arg and ignore the second. Output: Test: test
	int i = printf("%s\n", "123456");
	printf("Return of printf: %i\n", i);
	// printf return the number of char printed. Output: 7
	// 7 because \n is count as a printed char.
	printf("Test decimal: %d\n", 3.2);
	// printf doesnt write float with d format. print int.
	// Output: Test decimal: -1950100832
	printf("Test % \n");
	// printf write the % if there are not any tags with it.
	// Output: Test %
	printf("Test %");
	// print doesnt write % if there is nothing behind it.
	// Ouput: Test
	printf("\nTest %  skfjdkfj\n", "a");
	// printf write s even when not connect to %. See if for manda 
	// or bonus. Output: Test akfjdkfj
	
	return (0);
} */