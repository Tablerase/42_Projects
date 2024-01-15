/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 14:40:52 by rcutte            #+#    #+#             */
/*   Updated: 2024/01/13 17:06:53 by rcutte           ###   ########.fr       */
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
 * * Push the number to b and sort it in blocks
 * @infos: The blocks are sorted by pushing the numbers to b under a certain
 * median for each block
 * @param stacks: stacks to sort
 * @param max: median to reach
 */
static void	ft_sort_into_b(t_stacks *stacks, t_medians medians)
{
	while (ft_stack_size(stacks->a) > 0)
	{
		ft_push_b_med(stacks, medians.median1);
		ft_push_b_med(stacks, medians.median2);
		ft_push_b_med(stacks, medians.median3);
		ft_push_b_med(stacks, medians.median4);
		ft_push_b_med(stacks, medians.median5);
		ft_push_b_med(stacks, medians.median6);
	}
}

int	ft_top_part_b(t_stacks *stacks, int number)
{
	unsigned int	closest_node;
	t_node			*tmp;

	closest_node = 0;
	tmp = stacks->b->head;
	while (tmp)
	{
		if (tmp->value == number)
			break ;
		closest_node++;
		tmp = tmp->next;
	}
	if (closest_node > ft_stack_size(stacks->b) / 2)
		return (0);
	else
		return (1);
}

static void	ft_sort_into_a(t_stacks *stacks)
{
	int	max;

	while (ft_stack_size(stacks->b) > 0)
	{
		max = ft_stack_max(stacks->b);
		while (stacks->b->head && stacks->b->head->value != max)
		{
			if (ft_top_part_b(stacks, max))
				ft_sort_rotate(stacks->b, stacks);
			else
				ft_sort_reverse_rotate(stacks->b, stacks);
		}
		ft_sort_push_a(stacks);
	}
}

void	ft_sort_many(t_stacks *stacks)
{
	t_medians	medians;

	medians = ft_init_medians(stacks);
	ft_sort_into_b(stacks, medians);
	ft_sort_into_a(stacks);
}
