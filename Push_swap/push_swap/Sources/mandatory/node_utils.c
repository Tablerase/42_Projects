/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:47:30 by rcutte            #+#    #+#             */
/*   Updated: 2024/01/14 23:49:40 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

/**
 * *Calculate stack size
 * @param stack
 * @return size: size of the stack
*/
unsigned int	ft_stack_size(t_stack *stack)
{
	unsigned int	size;
	t_node			*tmp;

	size = 0;
	tmp = stack->head;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}

/**
 * *Calculate stack min
 * @params: stack
 * @return: stack min
*/
int	ft_stack_min(t_stack *stack)
{
	int		min;
	t_node	*tmp;

	if (!stack->head)
		return (ft_putstr_fd("Invalid read of stack->head", 2), 0);
	min = stack->head->value;
	tmp = stack->head;
	while (tmp)
	{
		if (tmp->value < min)
			min = tmp->value;
		tmp = tmp->next;
	}
	return (min);
}

/**
 * *Calculate stack max
 * @params: stack
 * @return: stack max
*/
int	ft_stack_max(t_stack *stack)
{
	int		max;
	t_node	*tmp;

	if (!stack->head)
		return (ft_putstr_fd("Invalid read of stack->head", 2), 0);
	max = stack->head->value;
	tmp = stack->head;
	while (tmp)
	{
		if (tmp->value > max)
			max = tmp->value;
		tmp = tmp->next;
	}
	return (max);
}

/**
 * * Bool to check if the number is in the top part of the stack
 * @param stacks: stacks structure
 * @param number: number to check
 * @param options: 0 for stack a, 1 for stack b
 * @return 1 if the number is in the top part of the stack, 0 if not
 */
int	ft_top_part(t_stacks *stacks, int number, int options)
{
	unsigned int	closest_node;
	t_node			*tmp;

	closest_node = 0;
	if (options == 0)
		tmp = stacks->a->head;
	else
		tmp = stacks->b->head;
	while (tmp)
	{
		if (tmp->value == number)
			break ;
		closest_node++;
		tmp = tmp->next;
	}
	if (options == 0)
	{
		if (closest_node > ft_stack_size(stacks->a) / 2)
			return (0);
	}
	else if (options == 1)
		if (closest_node > ft_stack_size(stacks->b) / 2)
			return (0);
	return (1);
}
