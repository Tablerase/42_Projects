/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:00:01 by rcutte            #+#    #+#             */
/*   Updated: 2024/01/31 15:12:32 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/pipex_bonus.h"

/**
 * *Executes the command
 * @param pipex The pipex structure
*/
void	ft_exec(t_pipex *pipex)
{
	ft_close_all(pipex);
	if (pipex->cmd_head->empty == 1)
		ft_exit(pipex, "Command not found", 127);
	pipex->path = ft_find_path(pipex->envp);
	pipex->cmd_head->cmd_path = ft_find_cmd(pipex->cmd_head->args[0],
			pipex->path);
	ft_check_cmd_access(pipex);
	execve(pipex->cmd_head->cmd_path, pipex->cmd_head->args, pipex->envp);
	ft_printf("Error: execve failed\n");
	ft_exit(pipex, NULL, EXIT_FAILURE);
}

/**
 * *Wait for all the processes
*/
void	ft_wait(t_pipex *pipex)
{
	int	i;

	ft_close_all(pipex);
	i = 0;
	while (i < pipex->cmd_count)
	{
		wait(&pipex->exit_status);
		i++;
	}
}
