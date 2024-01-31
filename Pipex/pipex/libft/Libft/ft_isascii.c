/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:27:23 by rcutte            #+#    #+#             */
/*   Updated: 2023/12/08 12:29:02 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
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
		if (ft_isascii(i))
			printf("%c", i);
	}
	printf("\n");
	for (int i = 0; i < 200; i++)
	{
		if (isascii(i))
			printf("%c", i);
	}
	return (0);
}
 */