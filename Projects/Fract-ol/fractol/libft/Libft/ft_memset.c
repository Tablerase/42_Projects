/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:34:24 by rcutte            #+#    #+#             */
/*   Updated: 2023/12/08 13:39:13 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(char *)(str + i) = c;
		i++;
	}
	return (str);
}

/* memset is not null protected */

/* 
#include <string.h>
#include <stdio.h>
int	main(int ac, char **av)
{
	printf("string: %s \n", av[1]);
	printf("result ft_: %s\n", (char *)ft_memset(av[1], av[2][0], av[3][0]));
	char *test = av[1];
	printf("result mem: %s", (char *)memset(test, av[2][0], av[3][0]));
	return (ac);
}
 */
/* 
#include <stdio.h>
#include <string.h>

int main () {
   char str[50];

   strcpy(str,"This is string.h library function");
   puts(str);

   memset(str,'$',7);
   puts(str);

   strcpy(str,"This is string.h library function");
   puts(str);

   ft_memset(str,'$',7);
   puts(str);
   
   return(0);
}
 */