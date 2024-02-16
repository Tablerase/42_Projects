/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:55:12 by rcutte            #+#    #+#             */
/*   Updated: 2023/11/01 19:02:08 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_size(int min, int max)
{
	int	result;

	result = 0;
	while ((min + result) != max)
		result++;
	return (result);
}

int	*ft_range(int min, int max)
{
	int	*list;
	int	size;
	int	i;

	i = 0;
	if (min >= max)
		return (NULL);
	size = ft_size(min, max);
	list = malloc(size * sizeof(int));
	if (list == NULL)
		return (NULL);
	while (i != size)
	{
		list[i] = min + i;
		i++;
	}
	return (list);
}
/*
#include<stdio.h>
int	main(int ac, char **av)
{
	printf("%i\n",ft_size(atoi(av[ac - 2]), atoi(av[ac - 1])));
	int *range = ft_range(atoi(av[ac - 2]), atoi(av[ac - 1]));
	for (int i = 0; i < ft_size(atoi(av[ac - 2]), atoi(av[ac - 1])); i++)
	{
		printf("%i|",range[i]);
	}
	return (0);
}
*/
