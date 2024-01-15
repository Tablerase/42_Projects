/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:58:53 by rcutte            #+#    #+#             */
/*   Updated: 2024/01/10 10:40:21 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

/**
 * *Free a stack
 * @params: stack
*/
void	ft_free_stack(t_stack *stack)
{
	t_node	*tmp;

	while (stack->head)
	{
		tmp = stack->head;
		stack->head = stack->head->next;
		free(tmp);
	}
	free(stack);
}

/**
 * *Free the stacks
 * @params: stacks
*/
void	ft_free_stacks(t_stacks *stacks)
{
	ft_free_stack(stacks->a);
	ft_free_stack(stacks->b);
	ft_free_stack(stacks->sort_sequence);
	free(stacks);
}

/**
 * *Exit the program with an error message
 * @description: Free the stacks before exit, print the error message
 * @params: Stacks, Error message
*/
void	ft_exit_error(t_stacks *stacks, char *msg)
{
	ft_free_stacks(stacks);
	ft_putstr_fd(msg, 2);
	exit(EXIT_FAILURE);
}
