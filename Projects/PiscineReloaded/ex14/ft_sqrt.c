/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:50:44 by rcutte            #+#    #+#             */
/*   Updated: 2023/10/30 17:21:22 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	a;

	a = 1;
	if (nb <= 0)
		return (0);
	while (a < 46500)
	{
		if (a * a == nb)
			return (a);
		else
			a++;
	}
	return (0);
}
/*
#include <stdio.h>
int main() {
	int	nb = -2147483648;
	printf("Nb :%i Square: %i", nb, ft_sqrt(nb));
    return 0;
}
*/
