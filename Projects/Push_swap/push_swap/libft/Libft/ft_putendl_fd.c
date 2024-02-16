/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:07:34 by rcutte            #+#    #+#             */
/*   Updated: 2023/12/08 13:39:29 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
Parameters 
s: The string to output.
fd: The file descriptor on which to write.

Return value 
None

External functs.
write

Description 
Outputs the string ’s’ to the given file descriptor
followed by a newline.
 */

#include "../Includes/libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (!s || !fd)
		return ;
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
/* 
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main (void)
{
	int	file;

	file = open("test.txt", O_CREAT | O_WRONLY);
	if (!file)
		return (printf("error open"));
	ft_putendl_fd("galette saucisse", file);
	ft_putstr_fd("after new line", file);
	char buffer[100];
	if (read(open("test.txt", O_RDONLY), buffer, 100) == -1)
		return (printf("error read"));
	printf("Inside file: %s", buffer);
}
 */