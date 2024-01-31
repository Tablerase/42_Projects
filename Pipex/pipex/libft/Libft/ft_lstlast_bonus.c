/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:46:24 by rcutte            #+#    #+#             */
/*   Updated: 2023/12/08 13:38:16 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
Parameters 
lst: The beginning of the list.

Return value 
Last node of the list

External functs. 
None

Description 
Returns the last node of the list.
 */

#include "../Includes/libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}
/* 
#include <stdio.h>
int main (void)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	t_list	*node4;
	
	node1 = ft_lstnew("A");
	node2 = ft_lstnew("B");
	node3 = ft_lstnew("C");
	node4 = ft_lstnew("D");

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;

	
	printf("Last: %s", (char *)ft_lstlast(node1)->content);
} */