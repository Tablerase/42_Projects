/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:03:24 by rcutte            #+#    #+#             */
/*   Updated: 2023/10/30 16:14:24 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	result;

	result = 1;
	if (nb >= 0)
	{
		while (nb >= 1)
		{
			result = result * nb;
			nb--;
		}
	}
	else
	{
		result = 0;
	}
	return (result);
}
/*
#include <stdio.h>
int main() {
	int	a = 6;
	printf("Facto: %i, Result: %i", a, ft_iterative_factorial(a)); 
    return 0;
}
*/
