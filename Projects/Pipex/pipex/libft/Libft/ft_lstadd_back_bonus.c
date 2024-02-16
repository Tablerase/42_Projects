/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:59:08 by rcutte            #+#    #+#             */
/*   Updated: 2023/12/08 13:37:35 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
Parameters 
lst: The address of a pointer to the first link of
a list.
new: The address of a pointer to the node to be
added to the list.

Return value 
None

External functs. 
None

Description 
Adds the node ’new’ at the end of the list.
 */
#include "../Includes/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	ft_lstlast(*lst)->next = new;
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

	t_list	*nodeadd = ft_lstnew("Last Add !!!");
	ft_lstadd_back(&node1, nodeadd);
	printf("Last: %s", (char *)ft_lstlast(node1)->content);
} */