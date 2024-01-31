/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:35:53 by rcutte            #+#    #+#             */
/*   Updated: 2024/01/31 13:03:49 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/pipex.h"

/**
 * * Find the PATH in the envp
 * @param envp The envp
 * @note The PATH is the variable that contains the path to the binaries
 * @return The PATH or NULL if not found
*/
char	*ft_find_path(char **envp)
{
	int		i;
	char	*path;

	i = 0;
	path = NULL;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path = ft_strdup(envp[i] + 5);
			if (path == NULL)
				return (ft_putstr_fd("Error path alloc\n", 2), NULL);
			break ;
		}
		i++;
	}
	if (path == NULL)
		return (ft_putstr_fd("PATH not found\n", 2), NULL);
	return (path);
}
