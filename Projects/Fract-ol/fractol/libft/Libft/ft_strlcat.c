/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:50:11 by rcutte            #+#    #+#             */
/*   Updated: 2023/12/08 13:40:25 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 

The strlcat() function appends the NUL-terminated string src to the end
     of dst.

It will append at most size - strlen(dst) - 1 bytes, NUL-ter‐
     minating the result.

Return
strlcat() functions return the total length of the
     string they tried to create.
For strlcat() that means the initial length of dst plus the
     length of src.
If strlcat() traverses size characters without
     finding a NUL, the length of the string is considered to be size and
     the destination string will not be NUL-terminated (since there was no
     space for the NUL).  This keeps strlcat() from running off the end of a
     string.  In practice this should not happen (as it means that either
     size is incorrect or that dst is not a proper “C” string).
*/

#include "../Includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	srclen;
	size_t	dstlen;

	if (size == 0 && !dst)
		return (ft_strlen(src));
	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	if (dstlen >= size)
		dstlen = size;
	if (dstlen == size)
		return (dstlen + srclen);
	if (srclen < size - dstlen)
		ft_memcpy(dst + dstlen, src, srclen + 1);
	else
	{
		ft_memcpy(dst + dstlen, src, size - dstlen - 1);
		dst[size - 1] = '\0';
	}
	return (dstlen + srclen);
}

/* 
#include <stdio.h>
#include <bsd/string.h>

void test(int size)
{
    char string[] = "Hello there,Venus";
    char buffer[20]= "TEST\0";
    int r;

    r = strlcat(buffer,string,size);

    printf("Copied '%s' into '%s', length %d\n",
            string,
            buffer,
            r
          );
}

void test2(int size)
{
    char string2[] = "Hello there,Venus";
    char buffer2[20]= "TEST\0";
    int r2;

    r2 = ft_strlcat(buffer2,string2,size);

    printf("FT Copied '%s' into '%s', length %d\n",
            string2,
            buffer2,
            r2
          );
}

int main()
{
    test(19);
	test2(19);
	test(10);
	test2(10);
    test(7);
	test2(7);
    test(0);
	test2(0);
    return(0);
} */