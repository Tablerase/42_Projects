/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:01:17 by rcutte            #+#    #+#             */
/*   Updated: 2024/01/20 15:05:17 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

/** 
 * *Create a new node
 * @params: value
 * @return: a new node
 */
t_node	*ft_node_new(int value)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
	{
		ft_putstr_fd("Error in mem alloc for node\n", 2);
		return (NULL);
	}
	new->value = value;
	new->moves = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

/**
 * *Add a node to the end of the stack
 * @params: stack, value
 */
void	ft_node_add_last(t_stack *stack, int value)
{
	t_node	*new;
	t_node	*tmp;

	new = ft_node_new(value);
	if (!new)
		return ;
	if (!stack->head)
	{
		stack->head = new;
		stack->size++;
		return ;
	}
	tmp = stack->head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
	stack->size++;
}

/**
 * *Add a node to the beginning of the stack
 * @params: stack, value
 */
void	ft_node_add_first(t_stack *stack, int value)
{
	t_node	*new;

	new = ft_node_new(value);
	if (!new)
		return ;
	new->next = stack->head;
	stack->head->prev = new;
	stack->head = new;
	stack->size++;
}

/**
 * *Delete the last node of the stack
 * @params: stack
 */
void	ft_node_del_last(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->prev->next = NULL;
	free(tmp);
	stack->size--;
}

/**
 * *Delete the first node of the stack
 * @params: stack
 */
void	ft_node_del_first(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->head;
	stack->head = stack->head->next;
	free(tmp);
	stack->size--;
}
