/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:14:37 by rcutte            #+#    #+#             */
/*   Updated: 2023/11/03 22:20:38 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "library.h"

int	main(int ac, char **av)
{
	int		file;
	int		file_read;
	char	buffer[1000];

	file_read = 0;
	if ((check_input(ac)) == -1)
		return (0);
	file = open(av[1], O_RDONLY);
	if (file == -1)
		return (file_error(file));
	file_read = read(file, buffer, 1000);
	if (file_read == -1)
		return (file_error(file));
	write(1, buffer, file_read);
	close(file);
	return (0);
}
