/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:35:45 by rcutte            #+#    #+#             */
/*   Updated: 2023/12/08 13:37:46 by rcutte           ###   ########.fr       */
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
Adds the node ’new’ at the beginning of the list.
 */
#include "../Includes/libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
/* 
#include <stdio.h>

int main (void)
{
	t_list	*list;
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	t_list	*node4;
	
	node1 = ft_lstnew("B");
	node2 = ft_lstnew("C");
	node3 = ft_lstnew("D");
	node4 = ft_lstnew("A");
	list = ft_lstnew("Previous Start");

	list->next = node1;
	node1->next = node2;
	node2->next = node3;
	ft_lstadd_front(&list, node4);
	int i = 0;
	while (list->next)
	{
		printf("Index: %i, Content: %s | Next: %p\n", i,
		(char *)list->content, list->next);
		list = list->next;
		i++;
	}
	printf("Index: %i, Content: %s | Next: %p\n", i,
		(char *)list->content, list->next);
} */