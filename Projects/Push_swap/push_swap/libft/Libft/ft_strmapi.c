/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:01:20 by rcutte            #+#    #+#             */
/*   Updated: 2023/12/08 13:40:45 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
Parameters 
s: The string on which to iterate.
f: The function to apply to each character.

Return value 
The string created from the successive applications
of ’f’.
Returns NULL if the allocation fails.

External functs. 
malloc

Description 
Applies the function ’f’ to each character of the
string ’s’, and passing its index as first argument
to create a new string (with malloc(3)) resulting
from successive applications of ’f’.
 */

#include "../Includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*edit_str;
	unsigned int	pos;

	if (!s)
		return (NULL);
	edit_str = ft_strdup((char *)s);
	if (!edit_str)
		return (NULL);
	pos = 0;
	while (edit_str[pos])
	{
		edit_str[pos] = f(pos, edit_str[pos]);
		pos++;
	}
	return (edit_str);
}
/* 
#include <stdio.h>

char	ft_test(unsigned int pos, char c)
{
	c = c + pos;
	return (c);
}

int main (int ac, char **av)
{
	printf("%s\n", ft_strmapi(av[ac - 1], &ft_test));
} */