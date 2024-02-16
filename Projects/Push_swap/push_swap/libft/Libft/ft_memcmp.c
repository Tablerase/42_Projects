/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:28:37 by rcutte            #+#    #+#             */
/*   Updated: 2023/12/08 13:38:52 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	position;

	position = 0;
	while (position < n)
	{
		if (*(unsigned char *)(s1 + position) !=
		*(unsigned char *)(s2 + position))
			return (*(unsigned char *)(s1 + position) -
			*(unsigned char *)(s2 + position));
		position++;
	}
	return (0);
}

/* 
#include <assert.h>
#include <stdio.h>
#include <string.h>
int main() {

    int array1 [] = { 54, 85, 20, 63, 21 };
    int array2 [] = { 54, 85, 19, 63, 21 };
    size_t size = sizeof( int ) * 5;

    assert( memcmp( array1, array2, size) == 
	ft_memcmp( array1, array2, size) );       
    assert( memcmp( array1, array1, size) == 
	ft_memcmp( array1, array1, size) );       
    assert( memcmp( array2, array1, size) == 
	ft_memcmp( array2, array1, size) );       
    
    printf( "Test is ok\n" );
    
    return 0;
}
 */