/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:20:56 by rcutte            #+#    #+#             */
/*   Updated: 2023/12/08 12:29:10 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

/* 
#include <stdio.h>
#include "libft.h"
int main(int ac, char **av)
{
	printf("char: %s int: %i -> is digit : %s\n", av[1], av[1][0], 
	ft_isdigit(av[1][0]) ? "true" : "false");
	return (ac);
}
 */