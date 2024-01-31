/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:46:35 by rcutte            #+#    #+#             */
/*   Updated: 2024/01/31 15:13:33 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/pipex_bonus.h"

/**
 * *Executes the first command
 * @param pipex The pipex structure
 * @param pipefd The pipefd
*/
void	ft_cmd0(t_pipex *pipex)
{
	ft_check_files(pipex, 0);
	ft_open_files(pipex, 0);
	dup2(pipex->infile_fd, STDIN_FILENO);
	dup2(pipex->fds[0][1], STDOUT_FILENO);
	ft_exec(pipex);
}

/**
 * *Executes the commands in the middle
 * @param pipex The pipex structure
 * @param pipefd The pipefd
*/
void	ft_cmdn(t_pipex *pipex, int position)
{
	int	i;

	i = 0;
	while (i < position)
	{
		if (pipex->cmd_head->next != NULL)
			ft_del_first_cmd(pipex);
		i++;
	}
	dup2(pipex->fds[position - 1][0], STDIN_FILENO);
	dup2(pipex->fds[position][1], STDOUT_FILENO);
	ft_exec(pipex);
}

/**
 * *Executes the last command
 * @param pipex The pipex structure
 * @param pipefd The pipefd
*/
void	ft_cmdlast(t_pipex *pipex, int position)
{
	int	i;

	i = 0;
	while (i < position)
	{
		if (pipex->cmd_head->next != NULL)
			ft_del_first_cmd(pipex);
		i++;
	}
	ft_check_files(pipex, 1);
	ft_open_files(pipex, 1);
	dup2(pipex->outfile_fd, STDOUT_FILENO);
	dup2(pipex->fds[position - 1][0], STDIN_FILENO);
	ft_exec(pipex);
}

/**
 * * Creating all the pipes in the fds array
 * @param pipex The pipex structure
*/
void	ft_init_fds(t_pipex *pipex)
{
	int	i;

	pipex->fds = malloc(sizeof(int *) * pipex->cmd_count);
	if (pipex->fds == NULL)
		ft_exit(pipex, "malloc failed\n", EXIT_FAILURE);
	i = 0;
	while (i < pipex->cmd_count)
	{
		pipex->fds[i] = malloc(sizeof(int) * 2);
		if (pipe(pipex->fds[i]) == -1)
			ft_exit(pipex, "pipe failed\n", EXIT_FAILURE);
		i++;
	}
}

void	ft_processes(t_pipex *pipex)
{
	int		i;
	pid_t	pid;

	ft_init_fds(pipex);
	i = 0;
	while (i < pipex->cmd_count)
	{
		pid = fork();
		if (pid == -1)
			ft_exit(pipex, "fork failed\n", EXIT_FAILURE);
		if (pid == 0)
		{
			if (i == 0)
				ft_cmd0(pipex);
			else if (i == pipex->cmd_count - 1)
				ft_cmdlast(pipex, i);
			else
				ft_cmdn(pipex, i);
		}
		i++;
	}
	ft_wait(pipex);
}
