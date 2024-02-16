/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:59:16 by rcutte            #+#    #+#             */
/*   Updated: 2023/12/08 13:37:52 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
Parameters 
lst: The address of a pointer to a node.
del: The address of the function used to delete
the content of the node.

Return value 
None

External functs. 
free

Description 
Deletes and frees the given node and every
successor of that node, using the function ’del’
and free(3).
Finally, the pointer to the list must be set to
NULL. */
#include "../Includes/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*to_del;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		to_del = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = to_del;
	}
}
