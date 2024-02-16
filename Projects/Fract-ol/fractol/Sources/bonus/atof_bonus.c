/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:10:50 by rcutte            #+#    #+#             */
/*   Updated: 2023/12/18 00:47:01 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/fractol_bonus.h"

/**
 * Atof decimal loop function
 * @param: string to convert
 * @param: number to convert
 * @param: decimal to convert
 * 
*/
static double	ft_atof_decimal_loop(
	const char *str,
	double nbr,
	double decimal)
{
	int	i;
	int	decimal_places;

	i = 0;
	decimal_places = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		decimal *= 10;
		decimal += str[i] - '0';
		i++;
		decimal_places++;
	}
	return ((nbr + (decimal / pow(10, decimal_places))));
}

/**
 * * Atof utility function
*/
static double	ft_atof_utils(
	const char *str,
	double nbr,
	double decimal,
	int sign)
{
	int	i;

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
		nbr *= 10;
		nbr += str[i] - '0';
		i++;
	}
	if (str[i] == '.')
	{
		i++;
		nbr = ft_atof_decimal_loop(str + i, nbr, decimal);
	}
	return (nbr * sign);
}

/**
 * * Convert a string to a double
 * @param: string to convert
 * @return: the converted string
*/
double	ft_atof(const char *str)
{
	double	number;
	double	decimal;
	int		sign;

	number = 0;
	decimal = 0;
	sign = 1;
	number = ft_atof_utils(str, number, decimal, sign);
	return (number);
}
