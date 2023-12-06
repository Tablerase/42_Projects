/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:00:31 by rcutte            #+#    #+#             */
/*   Updated: 2023/11/29 11:05:28 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include "stdlib.h"
# include "fcntl.h"
# include "unistd.h"

typedef struct t_str_list
{
	char			*content;
	int				file_read;
}	t_str_list;

char		*get_next_line(int fd);

size_t		ft_strlen(char *s);
int			ft_search_chr(char *s, char c);
char		*ft_strjoin(char *s1, char *s2);

char		*ft_strdup(char *src);
char		*ft_substr(char *s, unsigned int start, size_t len);

#endif
