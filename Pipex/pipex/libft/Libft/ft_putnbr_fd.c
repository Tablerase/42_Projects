/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:26:27 by rcutte            #+#    #+#             */
/*   Updated: 2023/12/08 13:39:36 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
Parameters 
n: The integer to output.
fd: The file descriptor on which to write.

Return value 
None

External functs. 
write

Description 
Outputs the integer ’n’ to the given file
descriptor. 
*/
#include "../Includes/libft.h"

/* 112 --> / 11 --> / 1 --> end of recursive call - write putchar n
			% 2		% 1

*/
void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		return (ft_putstr_fd("-2147483648", fd));
	if (n < 0)
	{
		n = -n;
		ft_putchar_fd('-', fd);
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	if (n < 10)
		ft_putchar_fd(n + '0', fd);
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
	ft_putnbr_fd(-2147483647, file);
	char buffer[100];
	if (read(open("test.txt", O_RDONLY), buffer, 100) == -1)
		return (printf("error read"));
	printf("Inside file: %s", buffer);
}
*/