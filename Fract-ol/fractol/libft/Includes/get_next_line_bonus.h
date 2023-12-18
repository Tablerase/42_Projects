/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:00:31 by rcutte            #+#    #+#             */
/*   Updated: 2023/12/08 13:47:36 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H

# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 40
# endif

// if you use ulimit -n to increase manually the limit, change OPEN_MAX macro
# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

typedef struct t_str_list
{
	char			*content;
	int				file_read;
}	t_str_list;

char	*get_next_line(int fd);

#endif