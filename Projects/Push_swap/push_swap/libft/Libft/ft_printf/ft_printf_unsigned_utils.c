/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:47:14 by rcutte            #+#    #+#             */
/*   Updated: 2023/12/08 12:23:38 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"
#include "../../Includes/libft.h"

// recursive call to fill str with number according to base
static char	*ft_uputnbr_rec(unsigned long long n, unsigned long basesize,
char *base, char *str)
{
	if (n >= basesize)
		ft_uputnbr_rec(n / basesize, basesize, base, str + 1);
	n = n % basesize;
	str[0] = base[n];
	return (str);
}

char	*ft_uputnbr_base(unsigned long long nbr, char *base, char *str)
{
	unsigned long	basesize;

	basesize = ft_strlen(base);
	ft_uputnbr_rec(nbr, basesize, base, str);
	return (str);
}
