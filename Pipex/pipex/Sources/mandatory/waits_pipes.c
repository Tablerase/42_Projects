/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waits_pipes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:51:05 by rcutte            #+#    #+#             */
/*   Updated: 2024/01/31 12:49:29 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/pipex.h"

/**
 * *Check the access of the command
 * @param pipex The pipex structure
 * @note Check if the command is executable and if it exists
*/
void	ft_check_cmd_access(t_pipex *pipex)
{
	if (pipex->cmd_head->cmd_path == NULL)
	{
		ft_putstr_fd(pipex->cmd_head->args[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		ft_exit(pipex, NULL, 127);
	}
	if (access(pipex->cmd_head->cmd_path, F_OK) == -1)
	{
		ft_putstr_fd(pipex->cmd_head->args[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		ft_exit(pipex, NULL, 127);
	}
	if (access(pipex->cmd_head->cmd_path, X_OK) == -1)
	{
		ft_putstr_fd(pipex->cmd_head->args[0], 2);
		ft_putstr_fd(": permission denied\n", 2);
		ft_exit(pipex, NULL, 126);
	}
}

/**
 * *Close the pipefd and the infile_fd and outfile_fd
 * @param pipex The pipex structure
 * @note Close all the pipefd and the infile_fd and outfile_fd
 * Allow to avoid leaks and errors with open file descriptors
*/
void	ft_close_all(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->cmd_count)
	{
		close(pipex->fds[i][0]);
		close(pipex->fds[i][1]);
		i++;
	}
	if (pipex->infile_fd != -1)
		close(pipex->infile_fd);
	if (pipex->outfile_fd != -1)
		close(pipex->outfile_fd);
}
