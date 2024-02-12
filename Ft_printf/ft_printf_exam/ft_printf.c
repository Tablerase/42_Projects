/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 22:31:29 by rcutte            #+#    #+#             */
/*   Updated: 2024/02/12 22:32:31 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_putchar(char c)
{
	int count;

	count = write(1, &c, 1);
	return (count);
}

int	ft_putstr(char *str)
{
	int	count;

	count = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (*str)
	{
		count += ft_putchar(*str);
		str++;
	}
	return (count);
}

int	ft_putnbr(int n)
{
	long long	ln;
	int		count;
	int		lim;
	int		sign;
	char	*str;

	count = 0;
	sign = 0;
	ln = (long long)n;
	str = malloc(12);
	if (ln == 0)
	{
		count += ft_putchar('0');
		return (count);
	}
	if (ln < 0)
	{
		count += ft_putchar('-');
		sign = -1;
		ln *= -1;
	}
	while (ln > 0)
	{
		str[count] = ln % 10 + '0';
		ln /= 10;
		count++;
	}
	int tmp = count;
	if (sign == -1)
		lim = 1;
	else
		lim = 0;
	while (count > 0 + lim)
	{
		count--;
		ft_putchar(str[count]);
	}
	free(str);
	return (tmp);
}

int ft_puthex(unsigned int n)
{
	int		count;
	char	*str;
	char	*hex;

	count = 0;
	str = malloc(12);
	hex = "0123456789abcdef";
	if (n == 0)
	{
		count += ft_putchar('0');
		return (count);
	}
	while (n > 0)
	{
		str[count] = hex[n % 16];
		n /= 16;
		count++;
	}
	int tmp = count;
	while (count > 0)
	{
		count--;
		ft_putchar(str[count]);
	}
	free(str);
	return (tmp);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	args;

	va_start(args, format);
	count = 0;
	if (!format)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'd')
				count += ft_putnbr(va_arg(args, int));
			else if (*format == 's')
				count += ft_putstr(va_arg(args, char *));
			else if (*format == 'c')
				count += ft_putchar(va_arg(args, int));
			else if (*format == 'x')
				count += ft_puthex(va_arg(args, unsigned int));
			else if (*format == '%')
				count += ft_putchar('%');
		}
		else
			count += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (count);
}

// #include <stdio.h>

// #ifndef REAL
// # define F	r += ft_printf
// #else
// # define F	r += printf
// #endif

// int
// 	main(void)
// {
// 	int	r;

// 	r = 0;
// 	F("Simple test\n");
// 	F("");
// 	F("--Format---");
// 	F("\n");
// 	F("%d\n", 0);
// 	F("%d\n", 42);
// 	F("%d\n", 1);
// 	F("%d\n", 5454);
// 	F("%d\n", (int)2147483647);
// 	F("%d\n", (int)2147483648);
// 	F("%d\n", (int)-2147483648);
// 	F("%d\n", (int)-2147483649);
// 	F("\n");
// 	F("%x\n", 0);
// 	F("%x\n", 42);
// 	F("%x\n", 1);
// 	F("%x\n", 5454);
// 	F("%x\n", (int)2147483647);
// 	F("%x\n", (int)2147483648);
// 	F("%x\n", (int)-2147483648);
// 	F("%x\n", (int)-2147483649);
// 	F("%x\n", (int)0xFFFFFFFF);
// 	F("\n");
// 	F("%s\n", "");
// 	F("%s\n", "toto");
// 	F("%s\n", "wiurwuyrhwrywuier");
// 	F("%s\n", NULL);
// 	F("-%s-%s-%s-%s-\n", "", "toto", "wiurwuyrhwrywuier", NULL);
// 	F("\n--Mixed---\n");
// 	F("%d%x%d%x%d%x%d%x\n", 0, 0, 42, 42, 2147483647, 2147483647, (int)-2147483648, (int)-2147483648);
// 	F("-%d-%x-%d-%x-%d-%x-%d-%x-\n", 0, 0, 42, 42, 2147483647, 2147483647, (int)-2147483648, (int)-2147483648);
// 	F("\n");
// 	F("%s%s%s%s\n", "", "toto", "wiurwuyrhwrywuier", NULL);
// 	F("-%s-%s-%s-%s-\n", "", "toto", "wiurwuyrhwrywuier", NULL);
// 	printf("written: %d\n", r);
// }