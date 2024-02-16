/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:51:49 by rcutte            #+#    #+#             */
/*   Updated: 2023/12/08 13:40:18 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
Function name 
ft_strjoin
Prototype 
char *ft_strjoin(char const *s1, char const *s2);
Parameters 
s1: The prefix string.
s2: The suffix string.
Return value 
The new string.
NULL if the allocation fails.
External functs. 
malloc
Description 
Allocates (with malloc(3)) and returns a new
string, which is the result of the concatenation
of ’s1’ and ’s2’.
 */

#include "../Includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	s1len;
	unsigned int	s2len;
	unsigned int	position;
	char			*str;

	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen((char *)s1);
	s2len = ft_strlen((char *)s2);
	str = malloc((s1len + s2len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	position = 0;
	while (position < s1len)
	{
		str[position] = s1[position];
		position++;
	}
	while (position < s1len + s2len)
	{
		str[position] = s2[position - s1len];
		position++;
	}
	str[position] = '\0';
	return (str);
}
/* 
#include <stdio.h>

int main(void)
{
	char *source1 = "Galette Saucisse";
	char *source2 = "Lait ribot";
	char *dest = ft_strjoin(source1, source2);
	printf("Result: %s", dest);
	free(dest);
	return (0);
}
 */