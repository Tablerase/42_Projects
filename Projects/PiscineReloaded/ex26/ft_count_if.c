/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:41:32 by rcutte            #+#    #+#             */
/*   Updated: 2023/11/02 18:22:49 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strs_len(char **tab)
{
	int	count;
	int	letter;

	count = 0;
	while (tab[count] != NULL)
	{
		letter = 0;
		while (tab[count][letter] != '\0')
		{
			letter++;
		}
		count++;
	}
	return (count);
}

int	ft_count_if(char **tab, int (*f)(char*))
{
	int	result;
	int	i;
	int	size;

	result = 0;
	i = 0;
	size = ft_strs_len(tab);
	while (i < size)
	{
		result = result + f(tab[i]);
		i++;
	}
	return (result);
}

int	ft_is_maj(char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (str[i])
	{
		if (str[i] >= 65 && str[i] <= 90)
			result = 1;
		else
			return (0);
		i++;
	}
	return (result);
}
/*
#include <stdio.h>
int main(int ac, char **av) {
    printf("Test maj:%i\n",  ft_is_maj("TEds"));
    printf("Test count:%i\n",  ft_strs_len(av));
	printf("%i\n",ft_count_if(av, ft_is_maj));
    return ac;
}
*/
