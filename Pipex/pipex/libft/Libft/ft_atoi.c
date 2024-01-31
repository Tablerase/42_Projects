/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 10:29:05 by rcutte            #+#    #+#             */
/*   Updated: 2023/12/08 12:26:35 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

int	ft_atoi(const char *str)
{
	int		number;
	int		i;
	int		sign;

	number = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number *= 10;
		number += str[i] - '0';
		i++;
	}
	return (number * sign);
}
/* 
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{		
	printf("42:%d\n", ft_atoi("  \n  42test42"));
	printf("42:%d\n", atoi("  \n  42test42"));
	printf("-42:%d\n", ft_atoi(" --+-42ests"));
	printf("-42:%d\n", atoi(" --+-42ests"));
	printf("0:%d\n", ft_atoi("\0 42"));
	printf("0:%d\n", atoi("\0 42"));
	printf("0:%d\n", ft_atoi("-0"));
	printf("0:%d\n", atoi("-0"));
	printf("0:%d\n", ft_atoi(" - 1 3 2 5 6 3 2 1 6 7"));
	printf("0:%d\n", atoi(" - 1 3 2 5 6 3 2 1 6 7"));
	printf("-123456789:%d\n", ft_atoi("-123456789"));
	printf("-123456789:%d\n", atoi("-123456789"));
	printf("-100:%d\n", ft_atoi("-100"));
	printf("-100:%d\n", atoi("-100"));
	printf("min:%d\n", ft_atoi("\t--2147483648"));
	printf("min:%d\n", atoi("\t--2147483648"));
	printf("max:%d\n", ft_atoi("\v2147483647"));
	printf("max:%d\n", atoi("\v2147483647"));
	return (0);
}
 */