/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:00:09 by rcutte            #+#    #+#             */
/*   Updated: 2023/11/27 19:25:36 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	{
		str[position] = s1[position];
		position++;
	}
	while (position < s1len + s2len)
	{
		str[position] = s2[position - s1len];
		position++;
	}
	str[position] = '\0';
	return (str);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	pos;

	if (!s)
		return (NULL);
	if (start > (unsigned int)ft_strlen((char *)s))
		return (ft_strdup(""));
	if (len >= ft_strlen(s))
		len = ft_strlen((s + start));
	substr = malloc((len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	pos = 0;
	while (s[start + pos] && pos < len)
	{
		substr[pos] = s[start + pos];
		pos++;
	}
	substr[pos] = '\0';
	return (substr);
}

char	*ft_strdup(char *src)
{
	int		n;
	int		i;
	char	*dest;

	n = ft_strlen(src);
	dest = malloc(n + 1 * sizeof(char));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
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
