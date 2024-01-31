/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:46:25 by rcutte            #+#    #+#             */
/*   Updated: 2024/01/30 14:47:57 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/pipex_bonus.h"

/**
 * * Delete the here_doc file
 * @note Delete the here_doc file if it exists and if it can be deleted
 * for example if file in use, it can't be deleted
 * @return 0 if the file was deleted, -1 if not
*/
int	ft_del_here_doc(void)
{
	if (access("here_doc", F_OK) == 0)
	{
		if (unlink("here_doc") == -1)
		{
			ft_putstr_fd("Error: Couldn't delete here_doc\n", 2);
			return (-1);
		}
	}
	return (0);
}

static void	ft_here_doc_loop(char *delimiter, int fd)
{
	char	*line;

	while (1)
	{
		write(1, HBLU, ft_strlen(HBLU));
		write(1, "📬 ", 6);
		write(1, "➜ ", 5);
		write(1, RESET, ft_strlen(RESET));
		line = get_next_line(0, 0);
		if (line == NULL)
			break ;
		if (ft_strncmp(line, delimiter, ft_strlen(delimiter)) == 0)
		{
			write(1, "📪\n", 6);
			get_next_line(0, 1);
			free(line);
			break ;
		}
		write(fd, line, ft_strlen(line));
		free(line);
	}
	close(fd);
}

/**
 * * Here_doc
 * @param delimiter The delimiter
 * @note Write the heredoc in a file called "here_doc"
*/
void	ft_here_doc(char *delimiter)
{
	int		fd;

	ft_del_here_doc();
	fd = open("here_doc", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd == -1)
	{
		ft_putstr_fd("Error: Couldn't create here_doc\n", 2);
		exit(2);
	}
	ft_here_doc_loop(delimiter, fd);
}
