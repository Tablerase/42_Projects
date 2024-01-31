/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:42:50 by rcutte            #+#    #+#             */
/*   Updated: 2024/01/25 16:58:51 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/pipex.h"

/**
 * * Check the arguments
 * @param argc The argc
 * @param argv The argv
 * @param pipex The pipex struct to store if here_doc is used(1) or not(0)
 * @note Check if the arguments are valid
 * @note here_doc needs 2 arguments (heredoc and delimiter)
*/
void	ft_check_args(int argc, char **argv)
{
	if (argc != 5)
	{
		ft_putstr_fd("Error: Wrong number of arguments\n", 2);
		ft_putstr_fd("Usage: ./pipex infile cmd1 cmd2 outfile\n", 2);
		exit(EXIT_FAILURE);
	}
	if (ft_strncmp(argv[1], "here_doc", 8) == 0 && argc == 5)
		ft_putstr_fd("Error: Here doc not support in mandatory\n", 2);
}

/**
 * * Count the amount of commands
 * @param argc The argc
 * @param pipex The pipex struct to know if here_doc is used or not
 * @note Count the amount of commands
*/
int	ft_cmd_counts(int argc)
{
	int	i;
	int	count;

	i = 2;
	count = 0;
	while (i < argc - 1)
	{
		count++;
		i++;
	}
	return (count);
}
