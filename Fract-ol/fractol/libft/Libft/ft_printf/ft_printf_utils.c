/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:17:39 by rcutte            #+#    #+#             */
/*   Updated: 2023/12/08 12:32:41 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Functions used by ft_printf

#include "../../Includes/libft.h"
#include "../../Includes/ft_printf.h"

// print char
int	ft_print_char(char c)
{
	int	printed;

	printed = write(1, &c, 1);
	return (printed);
}

// print string
int	ft_print_str(char *str)
{
	int	printed;

	printed = 0;
	if (str == NULL)
	{
		printed = write(1, "(null)", 6);
		return (printed);
	}
	if (!str)
		return (printed);
	printed = write(1, str, ft_strlen(str));
	return (printed);
}

// print reverse string (use because we get num in reverse from putnbr,
// execept minus sign)
int	ft_reverse_print_str(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len == 0)
		return (0);
	while (len >= 0)
	{
		if (str[len] == '\0')
			len--;
		write(1, &str[len], 1);
		len--;
	}
	return (ft_strlen(str));
}

// recursive call to fill str with number according to base
char	*ft_putnbr_rec(long long n, long basesize, char *base, char *str)
{
	if (n >= basesize)
		ft_putnbr_rec(n / basesize, basesize, base, str + 1);
	n = n % basesize;
	str[0] = base[n];
	return (str);
}

// convert base 10 number with a base and write result into a provided string
char	*ft_putnbr_base(long long nbr, char *base, char *str)
{
	int	basesize;

	basesize = ft_strlen(base);
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = -nbr;
		ft_putnbr_rec(nbr, basesize, base, str + 1);
	}
	else
		ft_putnbr_rec(nbr, basesize, base, str);
	return (str);
}
