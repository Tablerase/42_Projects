/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:33:29 by rcutte            #+#    #+#             */
/*   Updated: 2024/01/31 15:45:02 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/Includes/libft.h"
# include "color.h"

# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <string.h>
# include <errno.h>

/**
 * @param cmd_path The path of the command
 * @param empty The empty status (0 = false, 1 = true)
 * @param args The arguments of the command in one string
 * @param amount_args The amount of arguments (including the command)
 * @param next The next command
 * @param prev The previous command
*/
typedef struct s_cmd
{
	char			*cmd_path;
	int				empty;
	char			**args;
	int				amount_args;
	struct s_cmd	*next;
	struct s_cmd	*prev;
}	t_cmd;

/**
 * @param cmd_count The amount of commands
 * @param path The PATH
 * @param infile The infile path
 * @param infile_fd The infile fd
 * @param outfile The outfile path
 * @param outfile_fd The outfile fd
 * @param cmd_head The commands array with the arguments
 * (cmd[0].cmd = cmd, cmd[0].args = args)
 * @param pids The pids array
 * @param fds The fds arrays
 * @param envp The envp list
*/
typedef struct s_pipex
{
	int		here_doc;
	int		cmd_count;
	char	*path;
	char	*infile;
	int		infile_fd;
	char	*outfile;
	int		outfile_fd;
	t_cmd	*cmd_head;
	int		*pids;
	int		**fds;
	char	**envp;
	int		exit_status;
}	t_pipex;

// Args

void	ft_check_args(int argc, char **argv);
int		ft_cmd_counts(int argc);

// Init

void	ft_init_pipex(t_pipex *pipex, char **envp);
void	ft_init_cmds(char **argv, t_pipex *pipex, int amount_cmds);

// Files

void	ft_get_files(int argc, char **argv, t_pipex *pipex);
int		ft_check_files(t_pipex *pipex, int type);
void	ft_open_files(t_pipex *pipex, int type);
void	ft_close_all(t_pipex *pipex);

// Commands

t_cmd	*ft_new_cmd(void);
void	ft_cmd_add_last(t_pipex *pipex, t_cmd *new);
void	ft_del_first_cmd(t_pipex *pipex);
void	ft_del_one_cmd(t_cmd *cmd, t_pipex *pipex);
char	*ft_find_cmd(char *cmd, char *path);
void	ft_check_cmd_access(t_pipex *pipex);

// Processes

void	ft_processes(t_pipex *pipex);
void	ft_exec(t_pipex *pipex);

// Wait

void	ft_wait(t_pipex *pipex);

// Parsing

void	ft_init_pipex(t_pipex *pipex, char **envp);
void	ft_get_files(int argc, char **argv, t_pipex *pipex);
char	*ft_find_path(char **envp);

	// Utils

int		ft_strs_len(char **split);
int		ft_power(int nb, int power);

// Memory

void	ft_free_cmd(t_cmd *cmd);
void	ft_free_split(char **split);
void	ft_free_pipex(t_pipex *pipex);
void	ft_exit(t_pipex *pipex, char *error_msg, int exit_status);

// Debug

void	ft_print_cmds(t_pipex pipex);
void	ft_print_pipex(t_pipex pipex);

#endif
