/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:00:09 by rcutte            #+#    #+#             */
/*   Updated: 2023/11/24 17:11:11 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	unsigned int	s1len;
	unsigned int	s2len;
	unsigned int	position;
	char			*str;

	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	str = malloc((s1len + s2len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	position = 0;
	while (position < s1len)
		str[position++] = s1[position];
	while (position < s1len + s2len)
	{
		str[position] = s2[position - s1len];
		position++;
	}
	str[position] = '\0';
	return (str);
}

t_str_list	*ft_lstnew(void *content)
{
	t_str_list	*result;

	result = malloc(sizeof(t_str_list));
	if (!result)
		return (NULL);
	result -> content = content;
	result -> next_fd = NULL;
	return (result);
}

int	ft_search_chr(char *s, char c)
{
	int		i;

	i = 0;
	if (!s || !c)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}
