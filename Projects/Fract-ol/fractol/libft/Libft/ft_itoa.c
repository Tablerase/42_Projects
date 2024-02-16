/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:20:55 by rcutte            #+#    #+#             */
/*   Updated: 2023/12/08 13:37:17 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
Parameters 
n: the integer to convert.

Return value 
The string representing the integer.
NULL if the allocation fails.

External functs. malloc

Description Allocates (with malloc(3)) and returns a string
representing the integer received as an argument.
Negative numbers must be handled.
 */

#include "../Includes/libft.h"

static int	ft_digits(int number)
{
	int	result;

	result = 0;
	if (number == 0)
		return (1);
	if (number < 0)
		number = -number;
	while (number > 9)
	{
		number = number / 10;
		result++;
	}
	if (number > 0)
		result++;
	return (result);
}

static int	ft_power10(int power)
{
	int	result;

	result = 1;
	while (power--)
		result *= 10;
	return (result);
}

static char	*ft_num_to_str(char *str, int n, int digits)
{
	char	*temp;

	temp = str;
	if (n < 0)
	{
		*temp++ = '-';
		n = -n;
		digits--;
	}
	while (digits > 1)
	{
		*temp++ = (n / ft_power10(digits - 1)) + '0';
		n = n % ft_power10(digits - 1);
		digits--;
	}
	if (digits <= 1)
		*temp++ = n + '0';
	*temp = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	int		num_len;
	char	*strnum;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	num_len = 0;
	if (n < 0)
		num_len++;
	num_len += ft_digits(n);
	strnum = malloc((num_len + 1) * sizeof(char));
	if (!strnum)
		return (NULL);
	strnum = ft_num_to_str(strnum, n, num_len);
	return (strnum);
}

/* 
#include <stdio.h>

int main (void)
{
	printf("%i\n", ft_digits(-2147483647)); // INT Max : 10 digits
	printf("%i\n", ft_digits(7)); // 1 digits

	char buffer[11];
	printf("%s\n", ft_num_to_str(buffer, 101, 3));
	
	int number = 1074110625;
	printf("%i : %s\n", number, ft_itoa(number));
	
	int number1 = 1;
	printf("%i : %s\n", number1, ft_itoa(number1));
	
	int number2 = 0;
	printf("%i : %s\n", number2, ft_itoa(number2));
	
	int number3 = -1;
	printf("%i : %s\n", number3, ft_itoa(number3));
	
	int number4 = -2147483647;
	printf("%i : %s\n", number4, ft_itoa(number4));
	
} 
 */