/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:46:59 by rcutte            #+#    #+#             */
/*   Updated: 2023/12/08 13:41:36 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
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
		printf("%c", ft_toupper(i));
	}
	printf("\n");
	for (int i = 0; i < 200; i++)
	{
		printf("%c", toupper(i));
	}
	return (0);
}
 */