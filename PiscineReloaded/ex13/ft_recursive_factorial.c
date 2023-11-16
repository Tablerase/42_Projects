/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:16:04 by rcutte            #+#    #+#             */
/*   Updated: 2023/10/30 16:48:39 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb < 0 || nb > 13)
		return (0);
	else if (nb == 0 || nb == 1)
		return (1);
	else if (nb == 2)
		return (2);
	else if (nb > 1)
	{
		return ((nb) * ft_recursive_factorial(nb - 1));
	}
	else
	{
		return (0);
	}
}
/*
#include <stdio.h>
int main() {
	int	a = 14;
	printf("Num: %i, Facto: %i", a, ft_recursive_factorial(a));
    return 0;
}
*/
