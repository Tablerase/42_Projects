/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 20:37:00 by rcutte            #+#    #+#             */
/*   Updated: 2024/01/15 00:00:21 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

/**
 * * Push the number to the top of the stack b under a certain median
 * @param stacks: stacks to sort
 * @param max: median to reach
 */
static void	ft_push_b_med(t_stacks *stacks, int max)
{
	while (stacks->a->head && ft_stack_min(stacks->a) <= max)
	{
		if (stacks->a->head->value <= max)
			ft_sort_push_b(stacks);
		else
			ft_sort_rotate(stacks->a, stacks);
	}
}

/**
 * * Push the number to the top of the stack a under a certain median
 * @param stacks: stacks to sort
 * @param max: median to reach
*/
static void	ft_push_a_med(t_stacks *stacks, int max)
{
	while (stacks->b->head && ft_stack_min(stacks->b) <= max)
	{
		if (stacks->b->head->value <= max)
			ft_sort_push_a(stacks);
		else
			ft_sort_rotate(stacks->b, stacks);
	}
}

/**
 * * Sort stack a into stack b
 * @infos: The numbers are sorted by pushing the numbers to b under a certain
 * median for each block
 * @param stacks: stacks to sort
 * @param medians: medians to reach
*/
static void	ft_sort_into_b(t_stacks *stacks, t_medians medians)
{
	unsigned int	middle;

	middle = ft_stack_size(stacks->a) / 2;
	while (ft_stack_size(stacks->a) > middle)
		ft_push_b_med(stacks, medians.median7);
	while (ft_stack_size(stacks->b) > 0)
	{
		ft_push_a_med(stacks, medians.median1);
		ft_push_a_med(stacks, medians.median2);
		ft_push_a_med(stacks, medians.median3);
		ft_push_a_med(stacks, medians.median4);
		ft_push_a_med(stacks, medians.median5);
		ft_push_a_med(stacks, medians.median6);
		ft_push_a_med(stacks, medians.median7);
	}
	while (ft_stack_size(stacks->a) > middle)
	{
		ft_push_b_med(stacks, medians.median7);
		ft_push_b_med(stacks, medians.median8);
		ft_push_b_med(stacks, medians.median9);
		ft_push_b_med(stacks, medians.median10);
		ft_push_b_med(stacks, medians.median11);
		ft_push_b_med(stacks, medians.median12);
	}
}

/**
 * * Sort stack b into stack a
 * @infos: The numbers are sorted by pushing the numbers to a from
 * max to min
 * @param stacks: stacks to sort
*/
static void	ft_sort_into_a(t_stacks *stacks)
{
	int	max;

	while (ft_stack_size(stacks->b) > 0)
	{
		max = ft_stack_max(stacks->b);
		while (stacks->b->head && stacks->b->head->value != max)
		{
			if (ft_top_part(stacks, max, 1))
				ft_sort_rotate(stacks->b, stacks);
			else
				ft_sort_reverse_rotate(stacks->b, stacks);
		}
		ft_sort_push_a(stacks);
	}
}

void	ft_sort_big(t_stacks *stacks)
{
	t_medians	medians;

	medians = ft_init_medians_big(stacks);
	ft_sort_into_b(stacks, medians);
	ft_sort_into_a(stacks);
}
