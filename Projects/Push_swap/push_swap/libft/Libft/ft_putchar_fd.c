/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:04:39 by rcutte            #+#    #+#             */
/*   Updated: 2023/12/08 13:39:21 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
Parameters 
c: The character to output.
fd: The file descriptor on which to write.

Return value 
None

External functs. 
write

Description 
Outputs the character ’c’ to the given file
descriptor.
 */
#include "../Includes/libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/* 
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main (void)
{
	int	file;

	file = open("test.txt", O_CREAT | O_RDWR);
	if (!file)
		return (printf("error open"));
	ft_putchar_fd('c', file);
	char buffer[100];
	if (read(open("test.txt", O_RDONLY), buffer, 100) == -1)
		return (printf("error read"));
	printf("Inside file: %s", buffer);
}
 */