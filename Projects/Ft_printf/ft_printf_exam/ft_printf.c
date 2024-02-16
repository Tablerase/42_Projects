/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 22:31:29 by rcutte            #+#    #+#             */
/*   Updated: 2024/02/14 23:42:04 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

int	ft_putchar(char c)
{
	int count;

	count = write(1, &c, 1);
	return (count);
}

int	ft_putstr(char *str)
{
	int count;

	count = 0;
	if (!str)
	{
		count += write(1, "(null)", 6);
		return (count);
	}
	while (*str)
	{
		count += ft_putchar(*str);
		str++;
	}
	return (count);
}

int	ft_putnbr(int nb)
{
	char nb_return[12];
	int i;
	int count;
	long long number;

	count = 0;
	number = nb;
	if (number == 0)
	{
		count += ft_putchar('0');
		return (count);
	}
	if (number < 0)
	{
		count += ft_putchar('-');
		number *= -1;
	}
	i = 0;
	while (number != 0)
	{
		nb_return[i] = number % 10 + '0';
		number = number / 10;
		i++;
	}
	nb_return[i] = '\0';
	while (i > 0)
	{
		i--;
		count += ft_putchar(nb_return[i]);
	}
	return (count);
}

int	ft_puthex(unsigned int nb)
{
	char nb_return[12];
	int	count;
	int	i;

	i = 0;
	count = 0;
	char hex[] = "0123456789abcdef";
	if (nb == 0)
	{
		count += ft_putchar('0');
		return (count);
	}
	while (nb != 0)
	{
		nb_return[i] = hex[nb % 16];
		nb = nb / 16;
		i++;
	}
	nb_return[i] = '\0';
	while (i > 0)
	{
		i--;
		count += ft_putchar(nb_return[i]);
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list ptr;
	int 	count;

	count = 0;
	if (!format)
		return (-1);
	va_start(ptr, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 's')
				count += ft_putstr(va_arg(ptr, char *));
			else if (*format == 'd')
				count += ft_putnbr(va_arg(ptr, int));
			else if (*format == 'x')
				count += ft_puthex(va_arg(ptr, unsigned int));
			else if (*format == '%')
				count += ft_putchar('%');
		}
		else
		{
			count += ft_putchar(*format);
		}
		format++;
	}
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