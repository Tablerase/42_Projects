/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:45:05 by rcutte            #+#    #+#             */
/*   Updated: 2023/12/08 13:38:58 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*temp_src;
	char	*temp_dest;

	if (!dest || !src)
		return (dest);
	temp_src = (char *)src;
	temp_dest = (char *)dest;
	while (n--)
		*temp_dest++ = *temp_src++;
	return (dest);
}
/* 
#include <stdio.h>
#include <string.h>

char message2[60] = "abcdefghijklmnopqrstuvwxyz";
char temp[60];

int main(void)
{	
    strcpy(temp, message2);
    printf("\n\nOriginal message: %s", temp);
    memcpy(temp + 4, temp + 16, 10);
    printf("\nAfter ft_memcpy() without overlap:\t%s", temp);
    strcpy(temp, message2);
    memcpy(temp + 6, temp + 4, 10);
    printf("\nAfter ft_memcpy() with overlap:\t%s", temp);

    strcpy(temp, message2);
    printf("\n\nOriginal message: %s", temp);
    ft_memcpy(temp + 4, temp + 16, 10);
    printf("\nAfter memcpy() without overlap:\t%s", temp);
    strcpy(temp, message2);
    ft_memcpy(temp + 6, temp + 4, 10);
    printf("\nAfter memcpy() with overlap:\t%s\n", temp);

	return 0;
}
 */