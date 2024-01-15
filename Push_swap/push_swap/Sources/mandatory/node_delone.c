/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_delone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:35:35 by rcutte            #+#    #+#             */
/*   Updated: 2024/01/12 16:25:49 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

/**
 * *Delete one node
 * @infos: delete one node from a stack and free it, maintaining the links
 * @param node: node to delete
 * @param stack: stack to delete the node from
 */
void	ft_node_delone(t_node *node, t_stack *stack)
{
	if (!node)
		return ;
	if (node == stack->head)
	{
		stack->head = node->next;
		if (stack->head)
			stack->head->prev = NULL;
	}
	else if (node->next == NULL)
	{
		node->prev->next = NULL;
	}
	else
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}
	free(node);
}
