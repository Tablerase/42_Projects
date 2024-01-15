/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:17:59 by rcutte            #+#    #+#             */
/*   Updated: 2024/01/13 16:43:17 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

/**
 * * Split a string into a string array
 * @description: Split a string into a string array, using a delimiter
 * add a ./push_swap in the first index of the array
 * @params: string, delimiter
 * @return: string array
 */
char	**ft_split_argument(char const *s, char c)
{
	char	**strs;
	char	**strs2;
	int		size;

	if (!s)
		return (NULL);
	strs = ft_split(s, c);
	size = ft_split_size(strs);
	strs2 = malloc(sizeof(char *) * (size + 2));
	if (!strs2)
		return (NULL);
	strs2[0] = ft_strdup("./push_swap");
	strs2[size + 1] = NULL;
	size = 0;
	while (strs[size])
	{
		strs2[size + 1] = ft_strdup(strs[size]);
		size++;
	}
	ft_free_split(strs);
	return (strs2);
}

/**
 * * Count the amount of strings in a string array
 * @params: string array
 * @return: amount of strings
 */
int	ft_split_size(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		i++;
	return (i);
}

/**
 * *Free a string array
 * @params: string array
*/
void	ft_free_split(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}
