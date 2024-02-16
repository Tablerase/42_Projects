/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:52:40 by rcutte            #+#    #+#             */
/*   Updated: 2023/10/30 16:01:49 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a - (*div * b);
}
/*
#include <stdio.h>
int main() {
	int	a = 618;
	int	b = 4;
	int	div = 0;
	int	mod = 0;
	ft_div_mod(a, b, &div, &mod);
	printf("a = %i, b = %i, div = %i, mod = %i", a, b, div, mod);
    return 0;
}
*/
