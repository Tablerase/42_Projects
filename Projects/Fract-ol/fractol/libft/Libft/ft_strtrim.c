/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:29:42 by rcutte            #+#    #+#             */
/*   Updated: 2023/12/08 13:41:16 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
Function name 
ft_strtrim
Prototype 
char *ft_strtrim(char const *s1, char const *set);
Parameters 
s1: The string to be trimmed.
set: The reference set of characters to trim.
Return value 
The trimmed string.
NULL if the allocation fails.
External functs. 
malloc
Description 
Allocates (with malloc(3)) and returns a copy of
’s1’ with the characters specified in ’set’ removed
from the beginning and the end of the string.
 */

#include "../Includes/libft.h"

static int	ft_trimcmp(char c, char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	unsigned int	end;

	if (!s1)
		return (NULL);
	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	if (ft_strlen(set) == 0)
		return (ft_strdup((char *)s1));
	start = 0;
	while (ft_trimcmp(s1[start], (char *)set))
		start++;
	end = ft_strlen(s1) - 1;
	while (ft_trimcmp(s1[end], (char *)set) && end > 0)
		end--;
	if (start > end)
		return (ft_strdup(""));
	if (start == end)
		return (ft_substr(s1, start, 1));
	return (ft_substr(s1, start, end - start + 1));
}

//Test one start pos == end pos
/* 
#include <stdio.h>
int main (void)
{
	char	*test = "abcabbbaTababcb";
	char	*set = "abc";
	char	*trim = ft_strtrim(test, set);
	printf("Original: %s | %s", test, trim);
	free(trim);
	return (0);
}
 */
// test empty input and full set input
/* 
#include <stdio.h>

int	main (void)
{
	char *s1 = "abababa";
	char *s2 = "ab";

	char *result = ft_strtrim(s1, s2);
	printf("%s", result);

	printf("\nTEST 2:\n");
	char *s3 = "  \t \t \n   \n\n\n\t";
	char *s4 = " \n\t";
	char *result2 = ft_strtrim(s3, s4); 
	printf("%s", result2); // "" seg fault if no check for end > 0
	
	free(result);
	free(result2);
} */