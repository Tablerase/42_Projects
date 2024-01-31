/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 14:50:40 by rcutte            #+#    #+#             */
/*   Updated: 2024/01/30 15:28:19 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/pipex.h"

static	char	*ft_find_cmd_utils(char *cmd, char *path)
{
	char	**path_split;
	char	*cmd_path;
	char	*tmp;
	int		i;

	i = 0;
	path_split = ft_split(path, ':');
	if (path_split == NULL)
		return (ft_putstr_fd("Error path_split alloc\n", 2), NULL);
	while (path_split[i])
	{
		tmp = ft_strjoin(path_split[i], "/");
		cmd_path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (cmd_path == NULL)
			return (ft_free_split(path_split),
				ft_putstr_fd("Error cmd_path alloc\n", 2), cmd_path);
		if (access(cmd_path, F_OK) == 0)
			return (ft_free_split(path_split), cmd_path);
		free(cmd_path);
		i++;
	}
	ft_free_split(path_split);
	return (NULL);
}

/**
 * * Find the command in the PATH
 * @param cmd The command
 * @param path The PATH
 * @return The command with the path or NULL if not found
*/
char	*ft_find_cmd(char *cmd, char *path)
{
	char	*cmd_path;

	if (ft_strchr(cmd, '/') != NULL)
	{
		if (access(cmd, F_OK) == 0)
			return (ft_strdup(cmd));
		return (NULL);
	}
	cmd_path = ft_find_cmd_utils(cmd, path);
	return (cmd_path);
}
