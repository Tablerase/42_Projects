/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 22:55:40 by rcutte            #+#    #+#             */
/*   Updated: 2024/02/27 13:46:11 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

static bool	ft_isint(char *arg)
{
	if (ft_strlen(arg) >= 10)
	{
		printf("%s\n", arg);
		if (ft_strlen(arg) == 10)
		{
			if (ft_strncmp(arg, "2147483647", 10) <= 0)
				return (true);
		}
		if (ft_strlen(arg) == 11 && arg[0] == '-')
			if (ft_strncmp(arg, "-2147483648", 11) <= 0)
				return (true);
		return (false);
	}
	return (true);
}

static bool	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (true);
	else
		return (false);
}

static bool	ft_is_number(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == false)
			return (false);
		i++;
	}
	return (true);
}

static void	print_overflow(void)
{
	printf("%sError:%s Argument is too big\n", BRED, RESET);
	printf("%sUsage:%s only integers numbers are handled\n", BYEL, RESET);
}

/**
 * @brief Check if the arguments are valid
 * @param argc The number of arguments
 * @param argv The arguments
 * @return true If the arguments are valid,
 * false If the arguments are invalid
*/
bool	check_args(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
	{
		printf("%sError:%s Wrong number of arguments\n", BRED, RESET);
		printf("%sUsage:%s ./philo [number_of_philosophers] [time_to_die] \
[time_to_eat] [time_to_sleep] [optional: number_of_meals]\n", BYEL, RESET);
		return (false);
	}
	argv = argv + 1;
	while (*argv)
	{
		if (ft_is_number(*argv) == false || ft_strlen(*argv) > 10
			|| ft_strlen(*argv) == 0)
		{
			printf("%sError:%s Argument is not a valid number\n", BRED, RESET);
			printf("%sUsage:%s ./philo 5 800 200 200 7\n", BYEL, RESET);
			return (false);
		}
		if (ft_isint(*argv) == false)
		{
			print_overflow();
			return (false);
		}
		argv++;
	}
	return (true);
}
