/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:09:30 by rcutte            #+#    #+#             */
/*   Updated: 2023/12/08 12:28:39 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

int	ft_isalnum(int c)
{
	if (ft_isdigit(c) || ft_isalpha(c))
		return (1);
	else
		return (0);
}

/* 
#include <stdio.h>
#include "libft.h"
int main(int ac, char **av)
{
	printf("char: %s int: %i -> is alnum : %s\n", av[1], av[1][0], 
	ft_isalnum(av[1][0]) ? "true" : "false");
	return (ac);
}
*/