/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:31:43 by rcutte            #+#    #+#             */
/*   Updated: 2023/12/08 13:38:37 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
Parameters 
lst: The beginning of the list.

Return value 
The length of the list

External functs. 
None

Description 
Counts the number of nodes in a list.
 */
#include "../Includes/libft.h"

int	ft_lstsize(t_list *lst)
{
	int	result;

	result = 0;
	if (!lst)
		return (result);
	while (lst->next)
	{
		result++;
		lst = lst->next;
	}
	if (lst)
		result++;
	return (result);
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

	int i = ft_lstsize(node1);
	printf("Number of nodes: %i\n", i);
	while (i--)
	{
		printf("Content: %s | Next: %p\n",
			(char *)node1->content,
			node1->next);
		node1 = node1->next;
	}
} */