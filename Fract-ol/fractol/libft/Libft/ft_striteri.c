/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:26:16 by rcutte            #+#    #+#             */
/*   Updated: 2023/12/08 13:40:12 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
Parameters 
s: The string on which to iterate.
f: The function to apply to each character.

Return value 
None

External functs. 
None

Description 
Applies the function ’f’ on each character of
the string passed as argument, passing its index
as first argument. Each character is passed by
address to ’f’ to be modified if necessary.
 */
#include "../Includes/libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	pos;

	if (!s)
		return ;
	pos = 0;
	while (s[pos])
	{
		f(pos, &s[pos]);
		pos++;
	}
}
/* 
#include <stdio.h>

void	ft_test(unsigned int pos, char *s)
{
	while (*s)
	{
		*s++ = *s + pos;
	}
}

int main (int ac, char **av)
{
	ft_striteri(av[ac - 1], &ft_test);
	printf("%s\n", av[ac - 1]);
} */