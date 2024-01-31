/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 18:12:57 by rcutte            #+#    #+#             */
/*   Updated: 2024/01/31 14:52:26 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int		status;

	ft_check_args(argc, argv, &pipex);
	ft_init_pipex(&pipex, envp);
	pipex.cmd_count = ft_cmd_counts(argc, &pipex);
	if (pipex.cmd_count < 2)
		ft_exit(&pipex, "Error: Not enough commands\n", EXIT_FAILURE);
	ft_init_cmds(argv, &pipex, pipex.cmd_count);
	ft_get_files(argc, argv, &pipex);
	ft_processes(&pipex);
	ft_del_here_doc();
	status = pipex.exit_status;
	ft_free_pipex(&pipex);
	return (status);
}
