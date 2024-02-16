/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:13:30 by rcutte            #+#    #+#             */
/*   Updated: 2023/12/08 13:39:05 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*temp_dest;
	char	*temp_src;

	if (!dest || !src)
		return (dest);
	else if (dest < src)
	{
		temp_dest = (char *)dest;
		temp_src = (char *)src;
		while (n--)
			*temp_dest++ = *temp_src++;
	}
	else
	{
		temp_dest = (char *)dest + n - 1;
		temp_src = (char *)src + n - 1;
		while (n--)
			*temp_dest-- = *temp_src--;
	}
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
    ft_memmove(temp + 4, temp + 16, 10);
    printf("\nAfter ft_memmove() without overlap:\t%s", temp);
    strcpy(temp, message2);
    ft_memmove(temp + 6, temp + 4, 10);
    printf("\nAfter ft_memmove() with overlap:\t%s", temp);

    strcpy(temp, message2);
    printf("\n\nOriginal message: %s", temp);
    memmove(temp + 4, temp + 16, 10);
    printf("\nAfter memmove() without overlap:\t%s", temp);
    strcpy(temp, message2);
    memmove(temp + 6, temp + 4, 10);
    printf("\nAfter memmove() with overlap:\t%s\n", temp);

	return 0;
}
 */

/* Test for NULL - use gcc without tags */
/* 
#include <stdio.h>
#include <string.h>
int main ()
{
	//printf("ft_ test NULL 3 : %s", (char *)ft_memmove("test", NULL, 3));
	//seg fault
	//printf("test NULL 3 : %s", (char *)memmove("test", NULL, 3)); 
	//seg fault
	
	//printf("ft_ NULL test 3 : %s", (char *)ft_memmove(NULL, "test", 3));
	//seg fault
	//printf("NULL test 3 : %s", (char *)memmove(NULL, "test", 3)); 
	//seg fault
	
	//printf("ft_ NULL NULL 3 : %s", (char *)ft_memmove(NULL, NULL, 3));
	//null - check without extras tags
	//printf("NULL NULL 3 : %s", (char *)memmove(NULL, NULL, 3)); 
	//null
	return (0);
}
 */