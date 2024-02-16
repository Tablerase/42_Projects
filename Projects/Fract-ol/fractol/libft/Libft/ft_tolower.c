/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:56:38 by rcutte            #+#    #+#             */
/*   Updated: 2023/12/08 13:41:29 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return ('a' + (c - 'A'));
	else
		return (c);
}

/* 
#include <stdio.h>
#include <ctype.h>
#include "libft.h"

int main(void)
{
	for (int i = 0; i < 200; i++)
	{
		printf("%c", ft_tolower(i));
	}
	printf("\n");
	for (int i = 0; i < 200; i++)
	{
		printf("%c", tolower(i));
	}
	return (0);
}
 */