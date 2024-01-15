/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 17:15:34 by rcutte            #+#    #+#             */
/*   Updated: 2024/01/15 12:12:47 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

/**
 * * Prints an error message and exits the program
 * @param av the arguments
 * @param splitted 1 if the arguments are splitted, 0 if not
 * @return: leave the program, send an error to stderr (detected by makefile)
 * Error 1
 */
static void	ft_error(char **av, int splitted)
{
	ft_putstr_fd("Error\n", 2);
	if (splitted)
		ft_free_split(av);
	exit(EXIT_FAILURE);
}

/**
 * * Checks if the string is a number
 * @description: Allow negative numbers, but not two '-' in a row
 * @params: argc, argv
 * @param: splitted 1 if the arguments are splitted, 0 if not
 * @return: continue program if the arguments are valid, return an error if not
 */
static void	ft_isnumber(int ac, char **av, int splitted)
{
	int		i;
	char	*str;

	while (ac > 1)
	{
		str = av[ac - 1];
		if (ft_strlen(str) == 0)
			return (ft_error(av, splitted));
		i = 0;
		while (str[i])
		{
			if (str[i] == '-' && i == 0)
				i++;
			if (str[i] == '-' && i == 1)
				return (ft_error(av, splitted));
			else if (!ft_isdigit(str[i]))
				return (ft_error(av, splitted));
			i++;
		}
		ac--;
	}
}

/**
 * * Checks if the arguments are duplicates
 * @params: argc, argv
 * @param: splitted 1 if the arguments are splitted, 0 if not
 * @return: continue program if the arguments are valid, return an error if not
 */
static int	*ft_isdup(int ac, char **av, int *arguments, int splitted)
{
	int	i;
	int	j;

	i = 0;
	while (i < ac - 1)
	{
		arguments[i] = ft_atoi(av[i + 1]);
		i++;
	}
	i = 0;
	while (i < ac - 1)
	{
		j = i + 1;
		while (j < ac - 1)
		{
			if (arguments[i] == arguments[j])
				return (free(arguments), ft_error(av, splitted), NULL);
			j++;
		}
		i++;
	}
	return (arguments);
}

/**
 * * Checks if the arguments can be integers
 * @description: Use to prevent overflow when converting to int,
 * only check the size of the string, not the value
 * @params: argc, argv
 * @param: splitted 1 if the arguments are splitted, 0 if not
 * @return: continue program if the arguments are valid, return an error if not
 */
static void	ft_isint(int ac, char **av, int splitted)
{
	int		i;
	char	*str;

	i = 1;
	while (i < ac)
	{
		str = av[i];
		if (ft_strlen(str) >= 10)
		{
			if (ft_strlen(str) == 10)
			{
				if (ft_strncmp(str, "2147483647", 10) <= 0)
					return ;
			}
			if (ft_strlen(str) == 11 && str[0] == '-')
				if (ft_strncmp(str, "-2147483648", 11) <= 0)
					return ;
			return (ft_error(av, splitted));
		}
		i++;
	}
}

/**
* * Checks if the arguments are valid
* Check if the arguments are numbers, if they are not, return an error
* Check if the arguments are duplicates, if they are, return an error
* Check if the arguments are integers, if they are not, return an error
* If the arguments are valid, continue the program
* @params: ac, av
* @param: splitted 1 if the arguments are splitted, 0 if not
*/
void	ft_check_args(int ac, char **av, int splitted)
{
	int	*arguments;

	if (ac < 2)
		exit(EXIT_FAILURE);
	else
	{
		ft_isnumber(ac, av, splitted);
		ft_isint(ac, av, splitted);
		arguments = malloc(sizeof(int) * ac - 1);
		if (!arguments)
			return (ft_error(av, splitted));
		ft_isdup(ac, av, arguments, splitted);
		free(arguments);
	}
}
