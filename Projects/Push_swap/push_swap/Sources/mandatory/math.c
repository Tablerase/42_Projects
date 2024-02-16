/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:44:32 by rcutte            #+#    #+#             */
/*   Updated: 2024/01/11 16:12:52 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

/**
 * *Absolute value
 * @param number
 * @return absolute value of number
 */
unsigned int	ft_abs(int number)
{
	if (number < 0)
		return (number * -1);
	return (number);
}

/**
 * *Min value from inputs values
 * @param a input value
 * @param b input value
 * @param c input value
 * @param d input value
 * @return min value
 */
int	ft_min(int a, int b, int c, int d)
{
	int	min;

	min = a;
	if (b < min)
		min = b;
	if (c < min)
		min = c;
	if (d < min)
		min = d;
	return (min);
}
