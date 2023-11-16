/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:32:38 by rcutte            #+#    #+#             */
/*   Updated: 2023/11/01 15:07:49 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (*(s1 + i) == *(s2 + i) && *(s1 + i) != '\0')
	{
		i++;
	}
	return (*(s1 + i) - *(s2 + i));
}
/*
#include<stdio.h>
#include<string.h>
int	main(int ac, char **av)
{
	printf("%i", ft_strcmp(av[1], av[2]));
	printf("%i", strcmp(av[1], av[2]));
	return ac;
}
*/
