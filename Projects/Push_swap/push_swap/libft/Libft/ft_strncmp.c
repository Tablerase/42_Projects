/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:26:56 by rcutte            #+#    #+#             */
/*   Updated: 2023/12/08 13:40:53 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	position;

	position = 0;
	while (position < n && position <= (size_t)ft_strlen((char *)s1))
	{
		if (*(unsigned char *)(s1 + position) !=
		*(unsigned char *)(s2 + position))
			return (*(unsigned char *)(s1 + position) -
			*(unsigned char *)(s2 + position));
		position++;
	}
	return (0);
}

/* ft_len to prevent skipping \0 */

/* 
#include <assert.h>
#include <stdio.h>
#include <string.h>
int main() {

    char array1 [] = "tests";
    char array2 [] = "tes\0ts";
    size_t size = sizeof( char ) * 4;

    assert( strncmp( array1, array2, size) == 
	ft_strncmp( array1, array2, size) );       
    assert( strncmp( array1, array1, size) == 
	ft_strncmp( array1, array1, size) );       
    assert( strncmp( array2, array1, size) == 
	ft_strncmp( array2, array1, size) );       
    
    printf( "Test is ok\n" );
    
    return 0;
}
 */