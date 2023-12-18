/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:39:49 by rcutte            #+#    #+#             */
/*   Updated: 2023/12/08 13:38:04 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
Parameters 
lst: The node to free.
del: The address of the function used to delete
the content.

Return value 
None

External functs. 
free

Description 
Takes as a parameter a node and frees the memory of
the node’s content using the function ’del’ given
as a parameter and free the node. The memory of
’next’ must not be freed. */
#include "../Includes/libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
