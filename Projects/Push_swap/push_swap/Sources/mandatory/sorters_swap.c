/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorters_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:39:43 by rcutte            #+#    #+#             */
/*   Updated: 2024/01/03 17:41:53 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

/**
 * *Swap the first two elements at the top of stack
 * @description: Do nothing if there is only one or no elements
 * @params: stack to swap
 * @return: none
*/
void	ft_sort_swap(t_stack *stack, t_stacks *stacks)
{
	t_node	*tmp;

	if (stack->head && stack->head->next)
	{
		tmp = stack->head;
		stack->head = stack->head->next;
		tmp->next = stack->head->next;
		stack->head->next = tmp;
	}
	if (stack == stacks->a)
		ft_node_add_last(stacks->sort_sequence, 0);
	else
		ft_node_add_last(stacks->sort_sequence, 1);
}

/**
 * *Swap the first two elements at the top of stack a and b
 * @description: Do nothing if there is only one or no elements
 * @params: stack a and b to swap
 * @return: none
*/
void	ft_sort_swap_both(t_stacks *stacks)
{
	ft_sort_swap(stacks->a, stacks);
	ft_sort_swap(stacks->b, stacks);
	ft_node_del_last(stacks->sort_sequence);
	ft_node_del_last(stacks->sort_sequence);
	ft_node_add_last(stacks->sort_sequence, 2);
}
