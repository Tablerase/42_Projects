/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:34:51 by rcutte            #+#    #+#             */
/*   Updated: 2023/12/08 13:38:22 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
Parameters 
lst: The address of a pointer to a node.
f: The address of the function used to iterate on
the list.
del: The address of the function used to delete
the content of a node if needed.

Return value 
The new list.
NULL if the allocation fails.

External functs. 
malloc, free

Description 
Iterates the list ’lst’ and applies the function
’f’ on the content of each node. Creates a new
list resulting of the successive applications of
the function ’f’. The ’del’ function is used to
delete the content of a node if needed.
 */
#include "../Includes/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	t_list	*tmp;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		tmp = lst->next;
		new_node = ft_lstnew(f(lst->content));
		if (!new_node)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = tmp;
	}
	return (new_list);
}

/* 
#include <stdio.h>

static void *f_apply(void *node)
{
	void * r = malloc(sizeof(int)); 
	*(int*)r = *(int*)node + 1; 
	return (r);
}

static void del(void *node)
{
	if (node)
		freeList((t_list *)node->next);
	free(node);
}

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

	t_list *list = ft_lstmap(node1, f_apply, del);
	while (list)
	{
		printf("%s\n", (char *)list->content);
		list = list->next;
	}
} */