/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:00:31 by rcutte            #+#    #+#             */
/*   Updated: 2023/11/24 17:05:08 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

# include "stdlib.h"
# include "fcntl.h"
# include "unistd.h"

typedef struct t_str
{
	char			*content;
	struct t_str	*next_fd;
}	t_str_list;

char		*get_next_line(int fd);
int			ft_search_chr(char *s, char c);
t_str_list	*ft_lstnew(void *content);
size_t		ft_strlen(char *s);
char		*ft_strjoin(char *s1, char *s2);

#endif
