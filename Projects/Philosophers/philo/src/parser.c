/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:15:53 by rcutte            #+#    #+#             */
/*   Updated: 2024/02/27 12:16:00 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

/**
 * @brief Convert a string to an integer
 * @param str The string to convert
 * @return int The integer
*/
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

/**
 * @brief Print the usage
 * @note number_of_philosophers must be between 2 and 200
 * (to avoid too many philosophers and too many threads - limit the sys usage)
 * @note time_to_die, time_to_eat and time_to_sleep must be at least 60
 * (to avoid too fast execution and to be able to see the program running)
*/
static void	print_usage(void)
{
	printf("%sError:%s Invalid arguments\n", BRED, RESET);
	printf("%sUsage:%s ./philo [1 - 200] [60 - max] \
[60 - max] [60 - max] [1 - max]\n", BYEL, RESET);
	printf("\tmax: The maximum value of an integer\n");
}

/**
 * @brief Parse the arguments
 * @param core The core structure
 * @param argc The number of arguments
 * @param argv The arguments
 * @return true If the arguments are valid,
 * false If the arguments are invalid
*/
bool	parse_args(t_core *core, int argc, char **argv)
{
	if (argc == 5)
	{
		core->philo_count = ft_atoi(argv[1]);
		core->time_to_die = ft_atoi(argv[2]);
		core->time_to_eat = ft_atoi(argv[3]);
		core->time_to_sleep = ft_atoi(argv[4]);
		core->meal_count = -1;
	}
	else
	{
		core->philo_count = ft_atoi(argv[1]);
		core->time_to_die = ft_atoi(argv[2]);
		core->time_to_eat = ft_atoi(argv[3]);
		core->time_to_sleep = ft_atoi(argv[4]);
		core->meal_count = ft_atoi(argv[5]);
	}
	if (core->philo_count < 1 || core->philo_count > 200
		|| core->time_to_die < 60
		|| core->time_to_eat < 60 || core->time_to_sleep < 60
		|| (argc == 6 && core->meal_count < 1))
	{
		print_usage();
		return (false);
	}
	return (true);
}
