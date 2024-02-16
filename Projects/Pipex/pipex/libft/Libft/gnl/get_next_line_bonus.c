/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:59:52 by rcutte            #+#    #+#             */
/*   Updated: 2024/01/25 15:24:41 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
* *Bonus* * 
Parameters 
fd: The file descriptor to read from

Return value 
Read line: correct behavior
NULL: there is nothing else to read, or an error
occurred

External functs. read, malloc, free

Description 
Write a function that returns a line read from a
file descriptor
*/

/*
read 
return :
success -> num of bytes read
fail -> -1
0 -> if End Of File
*/

#include "../../Includes/libft.h"
#include "../../Includes/get_next_line_bonus.h"

static int	ft_search_chr(char *s, char c)
{
	int		i;

	i = 0;
	if (!s || !c)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

// * read and store buffer into storage content after previous saved char
// read_len pointer to use and modify it in different function
static void	ft_read_store(int fd, t_str_list *storage, int *read_len)
{
	char	*buffer;
	char	*content;

	while (!ft_search_chr(storage->content, '\n') || read(fd, &buffer, 0) > 0)
	{
		buffer = malloc(BUFFER_SIZE + 1 * sizeof(char));
		if (!buffer)
			return ;
		*read_len = (int)read(fd, buffer, BUFFER_SIZE);
		if (*read_len <= 0)
		{
			free(buffer);
			return ;
		}
		buffer[*read_len] = '\0';
		content = ft_strjoin(storage->content, buffer);
		free(storage->content);
		storage->content = content;
		free(buffer);
	}
}

// * check storage for \n and add line to result, 
// if not found send all storage because it's mean we reach the end ()
static char	*ft_line(t_str_list *storage)
{
	char	*result;
	char	*trimmed;
	int		n_pos;

	n_pos = 0;
	while (storage->content[n_pos])
	{
		if (storage->content[n_pos] == '\n')
		{
			n_pos++;
			break ;
		}
		n_pos++;
	}
	result = ft_substr(storage->content, 0, n_pos);
	if (n_pos == (int)ft_strlen(storage->content))
		trimmed = ft_strdup("");
	else
		trimmed = ft_substr(storage->content, n_pos,
				ft_strlen(storage->content));
	free(storage->content);
	storage->content = trimmed;
	return (result);
}

// * Function to create and free need elements
// cas 1: create list element;
// cas 2: free list element and mark as read;
static void	ft_list_manager(t_str_list *list, int fd, int cas)
{
	if (cas == 1)
	{
		list[fd].content = ft_strdup("");
		list[fd].file_read = 0;
	}
	if (cas == 2)
	{
		list[fd].file_read = 1;
		free(list[fd].content);
	}
}

// string send as ptr to char* into ft_line because we want to change
// the inside of string but save where str is stored to be able to return it.
// *Param: fill 
// allow to store if mem was free to prevent freeing already freed mem.
/**
 * * Get next line
 * @param fd The file descriptor to read from
 * @param status 1 to force free the storage, 0 for standard behavior
 * @return Read line: correct behavior
*/
char	*get_next_line(int fd, int status)
{
	static t_str_list	list[OPEN_MAX];
	char				*result;
	int					read_len;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1 || fd >= OPEN_MAX)
		return (NULL);
	if (status == 1)
		ft_list_manager(list, fd, 2);
	if (list[fd].file_read == 1)
		return (NULL);
	if (list[fd].content == NULL)
		ft_list_manager(list, fd, 1);
	read_len = 0;
	ft_read_store(fd, &list[fd], &read_len);
	if (read_len == 0 && ft_strlen(list[fd].content) == 0)
		return (ft_list_manager(list, fd, 2), NULL);
	result = ft_line(&list[fd]);
	if (read_len == 0 && ft_strlen(result) != 0)
		return (result);
	return (result);
}

/* 
#include "stdio.h"

int main (void)
{
	int	file = open("get_next_line.c", O_RDONLY);
	if (file == -1)
	{
		printf("Error open\n");
		return (-1);
	}
	int	file2 = open("get_next_line.h", O_RDONLY);
	if (file2 == -1)
	{
		printf("Error open\n");
		return (-1);
	}
	char *s;
	char *s2;
	int i = 0;

	while (1)
	{
		printf("|Try : %i|\n", i);
		s = get_next_line(file);
		printf("%s", s);
		s2 = get_next_line(file2);
		printf("%s", s2);
		i++;
		if (s2 == NULL && s == NULL)
		{
			free(s2);
			free(s);
			break ;
		}
		free(s);
		free(s2);
	}
	close(file2);
	close(file); 
} */
