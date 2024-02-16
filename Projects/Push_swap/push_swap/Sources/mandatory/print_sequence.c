/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sequence.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:56:14 by rcutte            #+#    #+#             */
/*   Updated: 2024/01/12 18:05:21 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

/**
 * *Print sort sequence values
 * @description: 0 = sa, 1 = sb, 2 = ss, 3 = pa, 4 = pb, 5 = ra, 6 = rb
 * 7 = rr, 8 = rra, 9 = rrb, 10 = rrr
 * @param node node containt to print
 */
void	ft_print_sort_sequence_values(t_node *tmp)
{
	if (tmp->value == 0)
		ft_printf("sa\n");
	else if (tmp->value == 1)
		ft_printf("sb\n");
	else if (tmp->value == 2)
		ft_printf("ss\n");
	else if (tmp->value == 3)
		ft_printf("pa\n");
	else if (tmp->value == 4)
		ft_printf("pb\n");
	else if (tmp->value == 5)
		ft_printf("ra\n");
	else if (tmp->value == 6)
		ft_printf("rb\n");
	else if (tmp->value == 7)
		ft_printf("rr\n");
	else if (tmp->value == 8)
		ft_printf("rra\n");
	else if (tmp->value == 9)
		ft_printf("rrb\n");
	else if (tmp->value == 10)
		ft_printf("rrr\n");
}

/**
 * *Print sort sequence
 * @param stacks
 */
void	ft_print_sort_sequence(t_stacks *stacks)
{
	t_node	*tmp;

	tmp = stacks->sort_sequence->head;
	while (tmp)
	{
		ft_sanitize_sequence(stacks);
		if (tmp)
		{
			ft_print_sort_sequence_values(tmp);
			tmp = tmp->next;
		}
	}
}
