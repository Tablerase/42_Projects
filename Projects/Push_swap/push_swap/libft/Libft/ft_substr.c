/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:10:39 by rcutte            #+#    #+#             */
/*   Updated: 2023/12/08 13:41:22 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
Description 
Allocates (with malloc(3)) and returns a substring
from the string ’s’.
The substring begins at index ’start’ and is of
maximum size ’len’.

Parameters
s: The string from which to create the substring.
start: The start index of the substring in the string ’s’.
len: The maximum length of the substring.

Return value 
The substring.
NULL if the allocation fails.
 */

#include "../Includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	pos;

	if (!s)
		return (NULL);
	if (start > (unsigned int)ft_strlen((char *)s))
		return (ft_strdup(""));
	if (len >= ft_strlen(s))
		len = ft_strlen((s + start));
	substr = malloc((len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	pos = 0;
	while (s[start + pos] && pos < len)
	{
		substr[pos] = s[start + pos];
		pos++;
	}
	substr[pos] = '\0';
	return (substr);
}

/* 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void)
{
	char *source = "Galette complete:"\
	"eau sel ble noire oeuf jambon emmental\n";
	printf("%s", source);
	char *buffer = ft_substr(source, 4, 8); //Sub: tte comp
	printf("Sub ft: %s\n", buffer);
	char *buffer2 = ft_substr(source, 5, 8); //Sub: te compl
	printf("Sub : %s", buffer2);
	
	free(buffer);
	return 0;
}
 */
/* 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void)
{
	char *source = "0123456789";
	printf("%s\n", source);
	char *buffer = ft_substr(source, 9, 10);
	printf("Sub ft: %s\n", buffer);
	
	free(buffer);
	return 0;
} */