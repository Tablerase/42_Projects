/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_few.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:28:15 by rcutte            #+#    #+#             */
/*   Updated: 2024/01/10 17:52:40 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

/**
 * *Sort two numbers
 * @params: stack
 */
void	ft_sort_two(t_stacks *stacks)
{
	if (stacks->a->head->value > stacks->a->head->next->value)
		ft_sort_swap(stacks->a, stacks);
}

/**
 * *Sort three numbers
 * @params: stacks
 */
void	ft_sort_three(t_stacks *stacks)
{
	int		a;
	int		b;
	int		c;

	a = stacks->a->head->value;
	b = stacks->a->head->next->value;
	c = stacks->a->head->next->next->value;
	if (a > b && b < c && a < c)
		ft_sort_swap(stacks->a, stacks);
	else if (a > b && b > c && a > c)
	{
		ft_sort_swap(stacks->a, stacks);
		ft_sort_reverse_rotate(stacks->a, stacks);
	}
	else if (a > b && b < c && a > c)
		ft_sort_rotate(stacks->a, stacks);
	else if (a < b && b > c && a < c)
	{
		ft_sort_swap(stacks->a, stacks);
		ft_sort_rotate(stacks->a, stacks);
	}
	else if (a < b && b > c && a > c)
		ft_sort_reverse_rotate(stacks->a, stacks);
}

/**
 * * Sort five numbers utils
 * @params: stacks
 */
static void	ft_sort_five_utils(t_stacks *stacks, int min)
{
	if (stacks->b->head->value == min)
	{
		ft_sort_push_a(stacks);
		ft_sort_push_a(stacks);
		ft_sort_rotate(stacks->a, stacks);
	}
	else
	{
		ft_sort_push_a(stacks);
		ft_sort_rotate(stacks->a, stacks);
		ft_sort_push_a(stacks);
	}
}

/**
 * * Sort five numbers
 * @description: sort five numbers by pushing the two smallest to stack b
 * then push back to stack a when stack a is sorted
 * @params: stacks
 */
void	ft_sort_five(t_stacks *stacks)
{
	int		i;
	int		min;
	int		max;

	i = 0;
	min = ft_stack_min(stacks->a);
	max = ft_stack_max(stacks->a);
	while (i < 2)
	{
		if (stacks->a->head->value == min || stacks->a->head->value == max)
		{
			ft_sort_push_b(stacks);
			i++;
		}
		else
			ft_sort_rotate(stacks->a, stacks);
	}
	if (stacks->a->size == 4)
		ft_sort_two(stacks);
	else
		ft_sort_three(stacks);
	ft_sort_five_utils(stacks, min);
}
