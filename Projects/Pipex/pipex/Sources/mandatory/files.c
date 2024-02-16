/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:49:01 by rcutte            #+#    #+#             */
/*   Updated: 2024/01/31 14:51:49 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/pipex.h"

/**
 * * Open the files
 * @param pipex The pipex struct
 * @param type The type of access infile = 0 and outfile = 1
 * @note Open the infile and outfile
*/
void	ft_open_files(t_pipex *pipex, int type)
{
	if (type == 0)
	{
		pipex->infile_fd = open(pipex->infile, O_RDONLY);
		if (pipex->infile_fd == -1)
			return (perror("Infile open: "), ft_exit(pipex, NULL, 1));
	}
	else
	{
		pipex->outfile_fd = open(pipex->outfile, O_CREAT | O_WRONLY
				| O_TRUNC, 0644);
		if (pipex->outfile_fd == -1)
			return (perror("Outfile open: "), ft_exit(pipex, NULL, 1));
	}
}

/**
 * * Check if infile and outfile are directories
 * @param pipex The pipex struct
 * @param type The type of access infile = 0 and outfile = 1
 * @note Check if infile and outfile are directories if they are, exit
*/
static void	ft_check_dir(t_pipex *pipex, int type)
{
	int	fd;

	if (type == 0)
	{
		fd = open(pipex->infile, __O_DIRECTORY);
		if (fd > 0)
		{
			close(fd);
			ft_putstr_fd(pipex->infile, 2);
			ft_putstr_fd(": infile is a directory\n", 2);
			ft_exit(pipex, NULL, EISDIR);
		}
	}
	else
	{
		fd = open(pipex->outfile, __O_DIRECTORY);
		if (fd > 0)
		{
			close(fd);
			ft_putstr_fd(pipex->outfile, 2);
			ft_putstr_fd(": outfile is a directory\n", 2);
			ft_exit(pipex, NULL, EISDIR);
		}
	}
}

/**
 * *Check if the files are valid and accessible
 * @param pipex The pipex struct
 * @param type The type of access infile = 0 and outfile = 1
 * @return 1 if the file is valid and accessible, else 0 if it's not
 * @note F_OK: Check if the file exists, R_OK: Check if the file is readable,
 * W_OK: Check if the file is writable
*/
int	ft_check_files(t_pipex *pipex, int type)
{
	int	fd;

	ft_check_dir(pipex, type);
	if (type == 0)
	{
		if (access(pipex->infile, F_OK) != 0)
			return (perror(pipex->infile), ft_exit(pipex, NULL, 127), 0);
		if (access(pipex->infile, R_OK) != 0)
			return (perror(pipex->infile), ft_exit(pipex, NULL, 0), 0);
	}
	else
	{
		if (access(pipex->outfile, F_OK) != 0)
		{
			fd = open(pipex->outfile, O_CREAT | O_WRONLY, 0644);
			close(fd);
			return (1);
		}
		if (access(pipex->outfile, W_OK) != 0)
			return (perror(pipex->outfile), ft_exit(pipex, NULL, 126), 0);
	}
	return (1);
}

/**
 * * Get the files
 * @param argc The argc
 * @param argv The argv
 * @param pipex The pipex struct
 * @note Get the infile and outfile and store them in pipex->infile
 * and pipex->outfile
*/
void	ft_get_files(int argc, char **argv, t_pipex *pipex)
{
	pipex->infile = ft_strdup(argv[1]);
	if (pipex->infile == NULL)
		ft_exit(pipex, "alloc infile failed\n", EXIT_FAILURE);
	pipex->outfile = ft_strdup(argv[argc - 1]);
	if (pipex->outfile == NULL)
		ft_exit(pipex, "alloc outfile failed\n", EXIT_FAILURE);
}
