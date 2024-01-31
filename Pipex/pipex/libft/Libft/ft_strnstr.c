/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:46:43 by rcutte            #+#    #+#             */
/*   Updated: 2023/12/08 13:41:00 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	position;
	size_t	position2;
	size_t	little_len;

	position = 0;
	position2 = 0;
	little_len = ft_strlen((char *)little);
	if (little_len == 0)
		return ((char *)big);
	while (position < len && big[position])
	{
		while (big[position + position2] == little[position2]
			&& (position2 + position < len) && big[position + position2])
		{
			if (position2 == little_len - 1)
				return ((char *)(big + position));
			position2++;
		}
		position2 = 0;
		position++;
	}
	return (NULL);
}
/* 
#include <bsd/string.h>
#include <stdio.h>

int	main()
{
	char *haystack = "Recette de galette: EAU SEL BLE-NOIRE";
	char *needle = "galette";

	printf("String original: %s\n", haystack);
	printf("ft: %s\n", ft_strnstr(haystack, needle, 20));
	printf("ft: %s", strnstr(haystack, needle, 20));
}
 */