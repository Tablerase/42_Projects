/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:03:56 by rcutte            #+#    #+#             */
/*   Updated: 2023/12/08 13:40:31 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	position;

	position = 0;
	if (size <= 0)
		return (ft_strlen((char *)src));
	else
	{
		while (*(src + position) != '\0' && position < size - 1)
		{
			*(dst + position) = *(src + position);
			position++;
		}
	}
	*(dst + position) = '\0';
	return (ft_strlen((char *)src));
}
/* 
#include <stdio.h>
int main (void)
{
	char src[] = "coucou";
	char dest[] = "AAAAAAAAAA";
	printf("%ld : %s", ft_strlcpy(dest, src, 6), dest);
}
 */
/* 
#include <stdio.h>
#include <bsd/string.h>

void test(int size)
{
    char string[] = "Hello there, Venus";
    char buffer[19];
    int r;

    r = strlcpy(buffer,string,size);

    printf("Copied '%s' into '%s', length %d\n",
            string,
            buffer,
            r
          );
}

void test2(int size)
{
    char string[] = "Hello there, Venus";
    char buffer[19];
    int r;

    r = ft_strlcpy(buffer,string,size);

    printf("FT Copied '%s' into '%s', length %d\n",
            string,
            buffer,
            r
          );
}

int main()
{
    test(19);
    test(10);
    test(1);
    test(0);
	test2(19);
    test2(10);
    test2(1);
    test2(0);
    return(0);
}
 */