/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:59:52 by rcutte            #+#    #+#             */
/*   Updated: 2023/12/01 12:29:27 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
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
#include "get_next_line.h"

// * read and store buffer into storage content after previous saved char
// read_len pointer to use and modify it in different function
void	ft_read_store(int fd, t_str_list *storage, int *read_len)
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

// check storage for \n and add line to result, if not found send all storage
// because it's mean we reach the end ()
char	*ft_line(t_str_list *storage)
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

// string send as ptr to char* into ft_line because we want to change
// the inside of string but save where str is stored to be able to return it.
// *Param: fill 
// allow to store if mem was free to prevent freeing already freed mem.
char	*get_next_line(int fd)
{
	static t_str_list	storage;
	char				*result;
	int					read_len;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1
		|| storage.file_read == 1)
		return (NULL);
	if (storage.content == NULL)
	{
		storage.content = ft_strdup("");
		storage.file_read = 0;
	}
	read_len = 0;
	ft_read_store(fd, &storage, &read_len);
	if (read_len == 0 && ft_strlen(storage.content) == 0)
		return (storage.file_read = 1, free(storage.content), NULL);
	result = ft_line(&storage);
	if (read_len == 0 && ft_strlen(result) != 0)
		return (result);
	return (result);
}
/* 
#include "stdio.h"

int main (void)
{
	int	file = open("Tester/files/big_line_with_nl", O_RDONLY);
	if (file == -1)
	{
		printf("Error open\n");
		return (-1);
	}
	char *s;
	int i = 0;

	while (1)
	{
		s = get_next_line(file);
		printf("|Try : %i|\n", i);
		printf("%s", s);
		i++;
		if (s == NULL)
		{
			free(s);
			break ;
		}
		free(s);
	}
	close(file); 
}
 */