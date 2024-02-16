/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorters_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:57:51 by rcutte            #+#    #+#             */
/*   Updated: 2024/01/03 17:42:15 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

/**
 * *Shift up all elements of stack by 1
 * @description: The first element becomes the last one
 * @params: stack to shift up
 * @return: none
*/
void	ft_sort_rotate(t_stack *stack, t_stacks *stacks)
{
	t_node	*tmp;
	t_node	*last;

	if (stack->head && stack->head->next)
	{
		tmp = stack->head;
		stack->head = stack->head->next;
		last = stack->head;
		while (last->next)
			last = last->next;
		last->next = tmp;
		tmp->next = NULL;
	}
	if (stack == stacks->a)
		ft_node_add_last(stacks->sort_sequence, 5);
	else
		ft_node_add_last(stacks->sort_sequence, 6);
}

/**
 * *Shift down all elements of stack by 1
 * @description: The last element becomes the first one
 * @params: stack to shift down
 * @return: none
*/
void	ft_sort_reverse_rotate(t_stack *stack, t_stacks *stacks)
{
	t_node	*tmp;
	t_node	*last;

	if (stack->head && stack->head->next)
	{
		last = stack->head;
		while (last->next->next)
			last = last->next;
		tmp = last->next;
		last->next = NULL;
		tmp->next = stack->head;
		stack->head = tmp;
	}
	if (stack == stacks->a)
		ft_node_add_last(stacks->sort_sequence, 8);
	else
		ft_node_add_last(stacks->sort_sequence, 9);
}

/**
 * *Shift up all elements of stack a and b by 1
 * @description: The first element becomes the last one
 * @params: stack a and b to shift up
 * @return: none
*/
void	ft_sort_rotate_both(t_stacks *stacks)
{
	ft_sort_rotate(stacks->a, stacks);
	ft_sort_rotate(stacks->b, stacks);
	ft_node_del_last(stacks->sort_sequence);
	ft_node_del_last(stacks->sort_sequence);
	ft_node_add_last(stacks->sort_sequence, 7);
}

/**
 * *Shift down all elements of stack a and b by 1
 * @description: The last element becomes the first one
 * @params: stack a and b to shift down
 * @return: none
*/
void	ft_sort_reverse_rotate_both(t_stacks *stacks)
{
	ft_sort_reverse_rotate(stacks->a, stacks);
	ft_sort_reverse_rotate(stacks->b, stacks);
	ft_node_del_last(stacks->sort_sequence);
	ft_node_del_last(stacks->sort_sequence);
	ft_node_add_last(stacks->sort_sequence, 10);
}
