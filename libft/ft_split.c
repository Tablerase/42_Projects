/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:06:14 by rcutte            #+#    #+#             */
/*   Updated: 2023/11/15 17:05:19 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Parameters 
s: The string to be split.
c: The delimiter character.

Return value 
The array of new strings resulting from the split.
NULL if the allocation fails.

External functs. malloc, free

Description Allocates (with malloc(3)) and returns an array
of strings obtained by splitting ’s’ using the
character ’c’ as a delimiter. The array must end
with a NULL pointer. 
*/
#include "libft.h"

/* static int	ft_sub_strlen(char const *str, char charset)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != charset)
		i++;
	return (i);
}

static int	ft_countstr(char const *str, char charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == charset)
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] && str[i] != charset)
			i++;
	}
	return (count);
}

static void	ft_cpy_without_c(char const *str, char *list, char charset)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != charset)
	{
		list[i] = str[i];
		i++;
	}
	list[i] = '\0';
}

static char	**ft_loop(char **list, int countstr, char const *s, char c)
{
	int		i;

	i = 0;
	while (i < countstr)
	{
		while (*s && *s == c)
			s++;
		if (*s != '\0')
		{
			list[i] = malloc((ft_sub_strlen(s, c) + 1) * sizeof(char));
			if (!list[i])
				return (NULL);
			ft_cpy_without_c(s, list[i], c);
			i++;
		}
		while (*s && *s != c)
			s++;
	}
	list[i] = 0;
	return (list);
}

char	**ft_split(char const *s, char c)
{
	char	**list;
	int		countstr;

	if (!s)
		return (NULL);
	countstr = ft_countstr(s, c);
	list = malloc((countstr + 1) * sizeof(char *));
	if (!list)
		return (NULL);
	list = ft_loop(list, countstr, s, c);
	return (list);
}
 */

static int	ft_countstr(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (count);
}

static void	ft_free_list(char **list, int wordcount)
{
	while (wordcount > 0)
	{
		free(list[wordcount]);
		wordcount--;
	}
	free(list);
}

static int ft_next_c(const char *str, char c)
{
	int	pos;

	pos = 0;
	while (*str && *str != c)
		pos++;
	return (pos);
}

static void	ft_list_fill(char **list, int wordcount, const char *src, char c)
{
	int		i;

	i = 0;
	while (i < wordcount)
	{
		while (*src && *src == c)
			src++;
		if (*src != '\0')
		{
			list[i] = malloc((ft_next_c(src, c) + 1) * sizeof(char));
			if (!list[i])
				return (ft_free_list(list, wordcount));
			list[i] = ft_substr(src, 0, ft_next_c(src, c));
			i++;
		}
		while (*src && *src != c)
			src++;
	}
	list[wordcount] = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**list;

	if (!s)
		return (NULL);
	list = malloc((ft_countstr(s, c) + 1) * sizeof(char *));
	if (!list)
		return (NULL);
	ft_list_fill(list, ft_countstr(s, c), s, c);
	return (list);
}


#include <stdio.h>

int main(int ac, char **av)
{
	
	char **list = ft_split(av[ac -2], *av[ac - 1]);
	printf("Split: %s\n", av[ac - 2]);
	int i = 0;
	while (*list)
	{
		printf("String %i: %s\n", i, *list);
		i++;
		list++;
	}
}
