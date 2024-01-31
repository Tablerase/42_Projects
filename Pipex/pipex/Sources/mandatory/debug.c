/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:16:13 by rcutte            #+#    #+#             */
/*   Updated: 2024/01/25 17:43:39 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/pipex.h"

/**
 * * Print the commands
 * @param pipex The struct
 * @note print all the commands in pipex->cmd struct array
 */
void	ft_print_cmds(t_pipex pipex)
{
	t_cmd	*tmp;
	int		i;
	int		j;

	tmp = pipex.cmd_head;
	i = 0;
	while (tmp)
	{
		j = 0;
		while (tmp->args[j])
		{
			if (j == 0)
				ft_printf("cmd[%d]: %s", i, tmp->args[j]);
			else
				ft_printf(" %s", tmp->args[j]);
			j++;
		}
		ft_printf(" | amount of args: %d", tmp->amount_args);
		ft_printf(" | cmd_path[%d]: %s\n", i, tmp->cmd_path);
		tmp = tmp->next;
		i++;
	}
}

/**
 * * Print the pipex struct
 * @param pipex The struct
 * @note print all the pipex struct
 */
void	ft_print_pipex(t_pipex pipex)
{
	ft_printf("path: %s\n", pipex.path);
	ft_printf("infile: %s\n", pipex.infile);
	ft_printf("outfile: %s\n", pipex.outfile);
	ft_print_cmds(pipex);
}
