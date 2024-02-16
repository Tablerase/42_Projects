/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:42:50 by rcutte            #+#    #+#             */
/*   Updated: 2024/01/25 16:58:51 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/pipex_bonus.h"

/**
 * * Check the arguments
 * @param argc The argc
 * @param argv The argv
 * @param pipex The pipex struct to store if here_doc is used(1) or not(0)
 * @note Check if the arguments are valid
 * @note here_doc needs 2 arguments (heredoc and delimiter)
*/
void	ft_check_args(int argc, char **argv, t_pipex *pipex)
{
	if (argc < 5)
	{
		ft_putstr_fd("Error: Wrong number of arguments\n", 2);
		ft_putstr_fd("Usage: ./pipex infile cmd1 cmd2 outfile\n", 2);
		ft_putstr_fd("Or: ./pipex here_doc delimiter cmd1 cmd2 outfile\n", 2);
		exit(EXIT_FAILURE);
	}
	if (ft_strncmp(argv[1], "here_doc", 8) == 0 && argc > 5)
	{
		if (ft_strlen(argv[2]) == 0)
		{
			ft_putstr_fd("Error: Wrong delimiter\n", 2);
			exit(EXIT_FAILURE);
		}
		pipex->here_doc = 1;
		ft_here_doc(argv[2]);
		return ;
	}
	else if (ft_strncmp(argv[1], "here_doc", 8) == 0 && argc <= 5)
	{
		ft_putstr_fd("Error: Wrong number of arguments\n", 2);
		ft_putstr_fd("Usage: ./pipex here_doc delimiter cmd1 cmd2 outfile\n", 2);
		exit(EXIT_FAILURE);
	}
	pipex->here_doc = 0;
}

/**
 * * Count the amount of commands
 * @param argc The argc
 * @param pipex The pipex struct to know if here_doc is used or not
 * @note Count the amount of commands
 * @note If here_doc is used, start at argv[3]
*/
int	ft_cmd_counts(int argc, t_pipex *pipex)
{
	int	i;
	int	count;

	i = 2;
	count = 0;
	if (pipex->here_doc == 1)
		i = 3;
	while (i < argc - 1)
	{
		count++;
		i++;
	}
	return (count);
}
