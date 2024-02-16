/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:51:50 by rcutte            #+#    #+#             */
/*   Updated: 2024/01/10 14:46:38 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

/**
 * *Utils print stacks debug
*/
static void	ft_print_stacks_utils(t_node *tmp, t_node *tmp2)
{
	ft_printf("A | B\n");
	ft_printf("------\n");
	while (tmp || tmp2)
	{
		if (!tmp && tmp2)
		{
			ft_printf("| %d\n", tmp2->value);
			tmp2 = tmp2->next;
		}
		else if (!tmp2 && tmp)
		{
			ft_printf("%d | \n", tmp->value);
			tmp = tmp->next;
		}
		else
		{
			ft_printf("%d | %d\n", tmp->value, tmp2->value);
			tmp = tmp->next;
			tmp2 = tmp2->next;
		}
	}
	ft_printf("------\n");
}

/**
 * *Print stacks
 * @params: stacks
 */
void	ft_print_stacks(t_stacks *stacks)
{
	t_node	*tmp;
	t_node	*tmp2;

	tmp2 = stacks->b->head;
	tmp = stacks->a->head;
	ft_print_stacks_utils(tmp, tmp2);
}

/**
 * *Utils print stacks debug
*/
static void	ft_print_stacks_moves_utils(t_node *tmp, t_node *tmp2)
{
	while (tmp || tmp2)
	{
		if (!tmp && tmp2)
		{
			ft_printf("| %d\n", tmp2->moves);
			tmp2 = tmp2->next;
		}
		else if (!tmp2 && tmp)
		{
			ft_printf("%d | \n", tmp->moves);
			tmp = tmp->next;
		}
		else
		{
			ft_printf("%d | %d\n", tmp->moves, tmp2->moves);
			tmp = tmp->next;
			tmp2 = tmp2->next;
		}
	}
}

/**
 * *Print Stack moves
 * @param stack: stack to print
*/
void	ft_print_stacks_moves(t_stacks *stacks)
{
	t_node	*tmp;
	t_node	*tmp2;

	tmp2 = stacks->b->head;
	tmp = stacks->a->head;
	ft_printf("🧮 Stack moves: 🧮\n");
	ft_print_stacks_moves_utils(tmp, tmp2);
	ft_printf("🧮 End of Stack moves 🧮\n");
}

/**
 * *Print Int Array
 * @param array: array of integers to print
 * @param size: size of the array
*/
void	ft_print_int_array(int *array, unsigned int size)
{
	unsigned int	i;

	i = 0;
	ft_printf("🧮 Array: 🧮\n");
	while (i < size)
	{
		ft_printf("%d ", array[i]);
		i++;
	}
	ft_printf("\n🧮 End of Array 🧮\n");
}
