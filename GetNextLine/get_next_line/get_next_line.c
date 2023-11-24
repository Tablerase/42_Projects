/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:59:52 by rcutte            #+#    #+#             */
/*   Updated: 2023/11/24 18:04:21 by rcutte           ###   ########.fr       */
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

void	ft_clean_mem(char *buffer, t_str_list *storage)
{
	free(buffer);
	free(storage->content);
	free(storage);
}

char	*ft_putstr_trim(t_str_list *storage, char *result)
{
	int		len_trim;
	int		pos;
	int		i;
	char	*post_trim;

	len_trim = 0;
	while (storage->content[len_trim] && storage->content[len_trim] != '\n')
		len_trim++;
	result = malloc(len_trim + 2 * sizeof(char));
	if (!result)
		return (NULL);
	pos = 0;
	while (pos++ < len_trim)
		result[pos] = storage->content[pos];
	result[len_trim] = '\n';
	result[pos + 1] = '\0';
	post_trim = malloc(ft_strlen(storage->content + pos + 1));
	if (!post_trim)
		return (NULL);
	i = 0;
	while (storage->content[pos + i])
		post_trim[i++] = storage->content[pos + i];
	free(storage->content);
	storage->content = post_trim;
	return (result);
}

/* 
Check read and check new line and store when new line overlapped
in read buffer.
We need pointer because we want to edit the variable/like there are global for
the others fonctions too.
*/
void	ft_read_store(int fd, t_str_list *storage, char *buffer, int *read_size)
{
	int	pos;

	pos = 0;
	while (*read_size > 0 && !ft_search_chr(storage->content, '\n'))
	{
		*read_size = (int)read(fd, buffer, BUFFER_SIZE);
		buffer[BUFFER_SIZE] = '\0';
		storage->content = ft_strjoin(storage->content, buffer);
		if (!storage->content)
			return ;
	}
}

/*
readsize init to 1 (because 0 is when EOF is reach) 
*/
char	*get_next_line(int fd)
{
	static t_str_list	*storage;
	char				*buffer;
	char				*result;
	int					read_size;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &buffer, 0) == -1)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!buffer)
		return (NULL);
	storage = ft_lstnew("");
	read_size = 1;
	ft_read_store(fd, storage, buffer, &read_size);
	result = ft_putstr_trim(storage, result);
	if (read_size == 0 && ft_strlen(storage->content) == 0)
		ft_clean_mem(buffer, storage);
	return (result);
}

#include "stdio.h"

int main (void)
{
	int	file = open("test.txt", O_RDONLY);
	char *s;
	int i = 0;

	printf("s: %s", get_next_line(file));
	/* s = get_next_line(file);
	while (s != NULL)
	{
		printf("|Try : %i|\n", i);
		printf("%s", s);
		s = get_next_line(file);
		i++;
	}
	free(s);
	close(file); */
}

/* 
	! First Try
// * Edit content of node to be what's left after triming
void	ft_trim_node_content(t_str_list node, char *str)
{
	int		len;
	int		i;
	char 	*trim;

	len = ft_strlen(str);
	trim = malloc(len + 1 * sizeof(char));
	if (!trim)
		return ;
	while (str[i] && i < len)
	{
		trim[i] = str[i];
		i++;
	}
	str[i] = '\0';
}
// * Return string to print
char	*ft_putstr_trim(t_str_list node)
{
	int		pos;
	int		len_before_n;
	char	*str;

	len_before_n = 0;
	pos = 0;
	while (node.content[len_before_n] != '\n')
		len_before_n++;
	str = malloc(len_before_n + 1 * sizeof(char));
	if (!str)
		return (NULL);
	while (node.content[pos] && pos <= len_before_n)
	{
		if (pos < len_before_n)
			str[pos] = node.content[pos];
		if (pos == len_before_n)
			str[pos] = '\n';
		pos++;
	}
	if (pos == len_before_n + 1)
			str[pos] = '\0';
	if (pos > len_before_n)
		ft_trim_node_content(node, (node.content + pos));
	return (str);
}

char	*get_next_line(int fd)
{
	static t_str_list	*str_node;
	char				*buffer;
	int					read_num;

	read_num = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str_node = ft_lstnew("");
	if (!str_node)
		return (NULL);
	while (read_num != 0 && ft_search_chr(str_node->content, '\n') != 1)
	{
		buffer = malloc(BUFFER_SIZE + 1 * sizeof(char));
		read_num = read(fd, buffer, BUFFER_SIZE);
		if (read_num == -1)
			return (free(str_node), NULL);
		buffer[BUFFER_SIZE] = '\0';
		str_node->content = ft_strjoin(str_node->content, buffer);
		free(buffer);
	}
	if (read_num == 0)
	{
		free(str_node);
		return(NULL);
	}
	return (ft_putstr_trim(*str_node));
}
 */
