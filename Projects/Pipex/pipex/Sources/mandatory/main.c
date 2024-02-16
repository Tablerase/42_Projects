/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:52:01 by rcutte            #+#    #+#             */
/*   Updated: 2024/01/31 15:52:08 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int		status;

	ft_check_args(argc, argv);
	ft_init_pipex(&pipex, envp);
	pipex.cmd_count = ft_cmd_counts(argc);
	ft_init_cmds(argv, &pipex, pipex.cmd_count);
	ft_get_files(argc, argv, &pipex);
	ft_processes(&pipex);
	status = pipex.exit_status;
	ft_free_pipex(&pipex);
	return (status);
}
