/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 13:08:28 by rcutte            #+#    #+#             */
/*   Updated: 2023/11/01 13:17:37 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
	{
		i++;
	}
	return (i);
}
/*
#include <stdio.h>
int	main(int ac, char *argv[])
{
	printf("%i\n", ft_strlen(argv[ac - 1]));
	return 0;
}
*/
