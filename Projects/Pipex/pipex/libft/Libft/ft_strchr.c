/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:12:42 by rcutte            #+#    #+#             */
/*   Updated: 2023/12/08 13:39:58 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}
/* 
#include <string.h>
#include <stdio.h>
int	main(int ac, char **av)
{
	printf("str: %s char: %c pointer: %s\n", 
	av[1], av[2][0], ft_strchr(av[1], av[2][0]));
	printf("str: %s char: %c pointer: %s\n", 
	av[1], av[2][0], strchr(av[1], av[2][0]));
	return (ac);
}
 */
/* 
#include <stdio.h>
#include <string.h>
int main()
{
	printf("ft test : %s", ft_strchr("test", 's'));
	printf("test : %s", strchr("test", 's'));

	//check if NULL str seg - strchr do (even if we can prevent it easyly)
	printf("ft test : %s", ft_strchr(NULL, '\0'));
	printf("test : %s", strchr(NULL, '\0'));
} */