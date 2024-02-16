/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:11:02 by rcutte            #+#    #+#             */
/*   Updated: 2023/12/08 13:38:30 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
Parameters 
content: The content to create the node with.

Return value 
The new node

External functs. 
malloc

Description 
Allocates (with malloc(3)) and returns a new node.
The member variable ’content’ is initialized with
the value of the parameter ’content’. The variable
’next’ is initialized to NULL.
 */
#include "../Includes/libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*result;

	result = malloc(sizeof(t_list));
	if (!result)
		return (NULL);
	result -> content = content;
	result -> next = NULL;
	return (result);
}
/* 
#include <stdio.h>

int main (void)
{
	t_list *test;

	char *string = "Galette Saucisse";
	test = ft_lstnew(string);
	printf("Content: %s | Next: %s", (char *)test->content, (char *)test->next);
} */