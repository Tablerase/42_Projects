/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 11:33:32 by rcutte            #+#    #+#             */
/*   Updated: 2024/01/14 20:38:05 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

/**
 * * Check if the stack is sorted
 * @description: check if the stack is sorted
 * @param stack: to check
 * @return 1 if the stack is sorted, 0 if not
*/
int	ft_is_sorted(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->head;
	if (!tmp)
		return (0);
	while (tmp && tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

/**
 * * Choose the sorting function according to the argument
 * @description: execute the corresponding function according to the argument
 * @params: stack a and b
*/
void	ft_choose_sorter(t_stacks *stacks, char *arg)
{
	if (!ft_strncmp(arg, "sa", 3))
		ft_sort_swap(stacks->a, stacks);
	else if (!ft_strncmp(arg, "sb", 3))
		ft_sort_swap(stacks->b, stacks);
	else if (!ft_strncmp(arg, "ss", 3))
		ft_sort_swap_both(stacks);
	else if (!ft_strncmp(arg, "pa", 3))
		ft_sort_push_a(stacks);
	else if (!ft_strncmp(arg, "pb", 3))
		ft_sort_push_b(stacks);
	else if (!ft_strncmp(arg, "ra", 3))
		ft_sort_rotate(stacks->a, stacks);
	else if (!ft_strncmp(arg, "rb", 3))
		ft_sort_rotate(stacks->b, stacks);
	else if (!ft_strncmp(arg, "rr", 3))
		ft_sort_rotate_both(stacks);
	else if (!ft_strncmp(arg, "rra", 4))
		ft_sort_reverse_rotate(stacks->a, stacks);
	else if (!ft_strncmp(arg, "rrb", 4))
		ft_sort_reverse_rotate(stacks->b, stacks);
	else if (!ft_strncmp(arg, "rrr", 4))
		ft_sort_reverse_rotate_both(stacks);
	else
		ft_exit_error(stacks, "Error during choose of sorter\n");
}

/**
 * * Select the sorting function according to the amount of arguments
 * @description: if there is less than 4 arguments, we use the sort_three
 * function, if there is less than 6 arguments, we use the sort_five function
 * else we use the sort_many function
 * @params: stack a and b, amount of arguments
*/
void	ft_sort_select(t_stacks *stacks, int amount)
{
	stacks->a->size = ft_stack_size(stacks->a);
	if (amount < 2 || ft_is_sorted(stacks->a))
		return ;
	else if (amount == 2)
		ft_sort_two(stacks);
	else if (amount == 3)
		ft_sort_three(stacks);
	else if (amount <= 5)
		ft_sort_five(stacks);
	else if (amount <= 100)
		ft_sort_many(stacks);
	else
		ft_sort_big(stacks);
}
