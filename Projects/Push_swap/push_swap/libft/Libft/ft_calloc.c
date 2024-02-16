/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:39:34 by rcutte            #+#    #+#             */
/*   Updated: 2023/12/08 16:54:25 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
void *calloc(size_t nmemb, size_t size);

Description:
The calloc() function allocates memory for an array of nmemb elements
       of size bytes each and returns a pointer  to  the  allocated  memory.
       The  memory is set to zero.  If nmemb or size is 0, then calloc() re‐
       turns either NULL, or a unique pointer value that can later  be  suc‐
       cessfully  passed to free().  If the multiplication of nmemb and size
       would result in integer overflow, then calloc() returns an error.  By
       contrast,  an integer overflow would not be detected in the following
       call to malloc(), with the result that an incorrectly sized block  of
       memory would be allocated:

           malloc(nmemb * size);

Return:
The malloc() and calloc() functions return a pointer to the allocated
       memory, which is suitably aligned for any built-in type.   On  error,
       these functions return NULL.  NULL may also be returned by a success‐
       ful call to malloc() with a size of zero, or by a successful call  to
       calloc() with nmemb or size equal to zero.

*/

#include "../Includes/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	check_overflow;

	if (((long long)size < 0 && nmemb != 0)
		|| (size != 0 && (long long)nmemb < 0))
		return (NULL);
	if (size != 0)
	{
		check_overflow = (nmemb * size) / size;
		if (check_overflow != nmemb)
			return (NULL);
	}
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

/* 
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int elements = 5;
	
	int *list = ft_calloc(elements, sizeof(int));
	if (!list)
		printf("Mem alloc error !!");
	for(int i= 0; i < elements; i++)
	{
		printf("%i|", list[i]);
	}
	printf("\n");
	for(int i= 0; i < elements; i++)
	{
		printf("%p|", list + i);
	}
	free(list);
	return (0);
}
 */

// size 0 && || nmemb 0 work with calloc
/* 
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int elements = 5;
	
	int *list = ft_calloc(0, 0);
	if (!list)
		printf("Mem alloc error !!");
	for(int i= 0; i < elements; i++)
	{
		printf("%i|", list[i]);
	}
	printf("\n");
	for(int i= 0; i < elements; i++)
	{
		printf("%p|", list + i);
	}
	free(list);
	return (0);
}
 */