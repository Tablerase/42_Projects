/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate_stacks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:37:09 by rcutte            #+#    #+#             */
/*   Updated: 2024/01/10 10:38:38 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

/**
 * *Duplicate a stack
 * @infos: duplicate a stack
 * @param stack to duplicate
 * @return duplicated stack
*/
t_stack	*ft_duplicate_stack(t_stack *stack)
{
	t_stack	*new;
	t_node	*tmp;

	new = ft_new_stack();
	tmp = stack->head;
	while (tmp)
	{
		ft_node_add_last(new, tmp->value);
		tmp = tmp->next;
	}
	return (new);
}

/**
 * *Duplicate the stacks
 * @infos: duplicate the stacks to simulate the moves
 * @param stacks to duplicate
 * @return duplicated stacks
*/
t_stacks	*ft_duplicate_stacks(t_stacks *stacks)
{
	t_stacks	*simulated_stacks;

	simulated_stacks = malloc(sizeof(t_stacks));
	if (!simulated_stacks)
		return (ft_putstr_fd("Error in mem alloc for stacks\n", 2), NULL);
	simulated_stacks->a = ft_duplicate_stack(stacks->a);
	simulated_stacks->b = ft_duplicate_stack(stacks->b);
	simulated_stacks->sort_sequence = \
		ft_duplicate_stack(stacks->sort_sequence);
	return (simulated_stacks);
}
