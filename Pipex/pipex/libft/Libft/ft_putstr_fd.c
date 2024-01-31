/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:48:38 by rcutte            #+#    #+#             */
/*   Updated: 2023/12/08 13:39:43 by rcutte           ###   ########.fr       */
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
Outputs the string ’s’ to the given file
descriptor. 
*/
#include "../Includes/libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s || !fd)
		return ;
	while (*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
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
	ft_putstr_fd("galette saucisse", file);
	char buffer[100];
	if (read(open("test.txt", O_RDONLY), buffer, 100) == -1)
		return (printf("error read"));
	printf("Inside file: %s", buffer);
} */