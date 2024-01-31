/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:08:30 by rcutte            #+#    #+#             */
/*   Updated: 2024/01/31 14:53:48 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/pipex.h"

/**
 * * Free the memory of the cmd struct and its content
 * @param cmd The struct
*/
void	ft_free_cmd(t_cmd *cmd)
{
	if (cmd->args != NULL)
		ft_free_split(cmd->args);
	if (cmd->cmd_path != NULL)
		free(cmd->cmd_path);
	free(cmd);
}

/**
 * * Delete all the cmds of the list
 * @param pipex The struct
 * @note Delete all the cmds of the list and free the memory
*/
void	ft_del_cmds(t_pipex *pipex)
{
	t_cmd	*tmp;

	tmp = pipex->cmd_head;
	while (tmp != NULL)
	{
		pipex->cmd_head = pipex->cmd_head->next;
		ft_free_cmd(tmp);
		tmp = pipex->cmd_head;
	}
	pipex->cmd_head = NULL;
}

/**
 * * Delete all the pipes
 * @param pipex The struct
 * @note Delete all the pipes and free the memory
*/
void	ft_del_pipes(t_pipex *pipex)
{
	int	i;

	i = 0;
	if (pipex->fds == NULL)
		return ;
	while (i < pipex->cmd_count)
	{
		if (pipex->fds[i] != NULL)
			free(pipex->fds[i]);
		i++;
	}
	if (pipex->fds != NULL)
		free(pipex->fds);
}

/**
 * * Free the memory of the struct
 * @param pipex The struct
*/
void	ft_free_pipex(t_pipex *pipex)
{
	if (!pipex)
		return ;
	if (pipex->path != NULL)
		free(pipex->path);
	if (pipex->infile != NULL)
		free(pipex->infile);
	if (pipex->outfile != NULL)
		free(pipex->outfile);
	if (pipex->pids != NULL)
		free(pipex->pids);
	if (pipex->fds != NULL)
		ft_del_pipes(pipex);
	while (pipex->cmd_head != NULL)
		ft_del_cmds(pipex);
}

/**
 * *Exit program and free the memory
 * @param pipex The struct to free
 * @param error_msg The error message
 * @param exit_status The exit status
*/
void	ft_exit(t_pipex *pipex, char *error_msg, int exit_status)
{
	if (error_msg != NULL)
	{
		ft_putstr_fd("Error: ", 2);
		ft_putstr_fd(error_msg, 2);
		ft_putstr_fd("\n", 2);
	}
	if (pipex->fds != NULL)
		ft_close_all(pipex);
	ft_free_pipex(pipex);
	exit(exit_status);
}
