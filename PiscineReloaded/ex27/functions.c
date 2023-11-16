/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 20:04:14 by rcutte            #+#    #+#             */
/*   Updated: 2023/11/03 22:19:28 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "library.h"

int	check_input(int ac)
{
	if (ac < 2)
	{
		write(1, "File name missing.\n", 19);
		return (-1);
	}
	if (ac > 2)
	{
		write(1, "Too many arguments.\n", 20);
		return (-1);
	}
	return (ac);
}

int	file_error(int file_descriptor)
{
	write(1, "Cannot read file.\n", 18);
	close(file_descriptor);
	return (-1);
}
