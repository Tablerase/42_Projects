/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:02:36 by rcutte            #+#    #+#             */
/*   Updated: 2023/11/06 17:14:57 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}
/* 
#include <stdio.h>
#include <ctype.h>
#include "libft.h"

int main(void)
{
	for (int i = 0; i < 200; i++)
	{
		if (ft_isprint(i))
			printf("%c", i);
	}
	printf("\n");
	for (int i = 0; i < 200; i++)
	{
		if (isprint(i))
			printf("%c", i);
	}
	return (0);
}
 */