/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:39:26 by rcutte            #+#    #+#             */
/*   Updated: 2023/12/08 13:41:09 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}

/* 
#include <string.h>
#include <stdio.h>
int	main(int ac, char **av)
{
	printf("str: %s char: %c pointer: %s\n", av[1], av[2][0], 
	ft_strrchr(av[1], av[2][0]));
	printf("str: %s char: %c pointer: %s\n", 
	av[1], av[2][0], strrchr(av[1], av[2][0]));
	return (ac);
}
*/