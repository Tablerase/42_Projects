/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:32:35 by rcutte            #+#    #+#             */
/*   Updated: 2023/11/01 17:53:46 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *s)
{
	int	result;

	result = 0;
	while (*(s + result))
		result++;
	return (result);
}

char	*ft_strdup(char *src)
{
	int		size;
	char	*dest;

	size = ft_strlen(src);
	dest = malloc((size + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	while (*src)
		*dest++ = *src++;
	return (dest - size);
}
/*
#include<string.h>
#include<stdio.h>
int main(int ac, char **av)
{
	printf("%s\n",ft_strdup(av[ac - 1]));
	printf("%s\n",strdup(av[ac - 1]));
	return (0);
}
*/
