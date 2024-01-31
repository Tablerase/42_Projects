/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:36:24 by rcutte            #+#    #+#             */
/*   Updated: 2024/01/31 14:55:02 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/pipex_bonus.h"

/**
 * * Init the pipex struct
 * @param pipex The struct
 * @param envp The envp
 * @note Init the pipex struct with the arguments
 */
void	ft_init_pipex(t_pipex *pipex, char **envp)
{
	pipex->envp = envp;
	pipex->cmd_count = 0;
	pipex->path = NULL;
	pipex->pids = NULL;
	pipex->fds = NULL;
	pipex->infile = NULL;
	pipex->outfile = NULL;
	pipex->infile_fd = -1;
	pipex->outfile_fd = -1;
	pipex->cmd_head = NULL;
}

static void	ft_init_cmds_utils(t_pipex *pipex, char **cmd)
{
	t_cmd	*new_cmd;

	ft_free_split(cmd);
	new_cmd = ft_new_cmd();
	new_cmd->empty = 1;
	new_cmd->args = NULL;
	new_cmd->amount_args = 0;
	new_cmd->cmd_path = NULL;
	ft_cmd_add_last(pipex, new_cmd);
}

/**
 * * Init the cmd struct
 * @param cmd The struct
 * @param pipex The pipex struct
 * @note Init the cmd struct with the arguments
 */
void	ft_init_cmds(char **argv, t_pipex *pipex, int amount_cmds)
{
	int		i;
	int		start;
	char	**cmd;
	t_cmd	*new_cmd;

	i = 0;
	if (pipex->here_doc == 1)
		start = 3;
	else
		start = 2;
	while (i < amount_cmds)
	{
		cmd = ft_split(argv[i + start], ' ');
		if (cmd == NULL || *cmd == NULL)
			ft_init_cmds_utils(pipex, cmd);
		else
		{
			new_cmd = ft_new_cmd();
			new_cmd->args = cmd;
			new_cmd->amount_args = ft_strs_len(cmd);
			ft_cmd_add_last(pipex, new_cmd);
		}
		i++;
	}
}
