/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:43:49 by rcutte            #+#    #+#             */
/*   Updated: 2023/11/06 13:32:26 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	else
		return (0);
}

/*
#include <stdio.h>
#include "libft.h"
int main(int ac, char **av)
{
	printf("char: %s -> is alpha : %s", av[1], 
	ft_isalpha(av[1][0]) ? "true" : "false");
	return (ac);
}*/