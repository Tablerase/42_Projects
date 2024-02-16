/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorters_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 18:00:16 by rcutte            #+#    #+#             */
/*   Updated: 2024/01/03 17:40:58 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

/**
 * *Take the first element at the top of a and put it at the top of b
 * @description: Do nothing if a is empty
 * @params: stack a and b
 * @return: none
*/
void	ft_sort_push_b(t_stacks *stacks)
{
	t_node	*tmp;

	if (stacks->a->head)
	{
		tmp = stacks->a->head;
		stacks->a->head = stacks->a->head->next;
		tmp->next = stacks->b->head;
		stacks->b->head = tmp;
	}
	ft_node_add_last(stacks->sort_sequence, 4);
}

/**
 * *Take the first element at the top of b and put it at the top of a
 * @description: Do nothing if b is empty
 * @params: stack a and b
 * @return: none
*/
void	ft_sort_push_a(t_stacks *stacks)
{
	t_node	*tmp;

	if (stacks->b->head)
	{
		tmp = stacks->b->head;
		stacks->b->head = stacks->b->head->next;
		tmp->next = stacks->a->head;
		stacks->a->head = tmp;
	}
	ft_node_add_last(stacks->sort_sequence, 3);
}
