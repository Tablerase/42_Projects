/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sanitize_sequence.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:39:25 by rcutte            #+#    #+#             */
/*   Updated: 2024/01/12 18:04:09 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

/**
 * *Init occurences structures
 * @param option 0 = ra and rb, 1 = rra and rrb
 * @return struct
 */
static t_occurences	ft_init_occurences(int option)
{
	t_occurences	result;

	result.list1.amount = 0;
	result.list1.node = NULL;
	result.list2.amount = 0;
	result.list2.node = NULL;
	if (option == 0)
	{
		result.list1.key = 5;
		result.list2.key = 6;
		result.new_instru = 7;
	}
	else if (option == 1)
	{
		result.list1.key = 8;
		result.list2.key = 9;
		result.new_instru = 10;
	}
	else
		ft_putstr_fd("Error in option assignation: ft_init_occurences\n", 2);
	return (result);
}

/**
 * *Delete occurences - part 2
*/
static void	ft_del_occu_part2(t_occurences list, t_stacks *stacks)
{
	t_node	*tmp;
	t_node	*tmp2;
	int		i;

	if (list.list1.amount > list.list2.amount && list.list2.amount > 0
		&& list.list1.amount > 0)
	{
		tmp = list.list2.node;
		i = list.list2.amount;
		while (tmp && i > 0)
		{
			tmp2 = tmp->next;
			ft_node_delone(tmp, stacks->sort_sequence);
			i--;
			tmp = tmp2;
		}
		tmp = list.list1.node;
		while (tmp && list.list2.amount-- > 0)
		{
			tmp->value = list.new_instru;
			tmp = tmp->next;
		}
	}
}

/**
 * *Delete occurences of the following list: ra and rb, rra and rrb
 * @param struct containing the informations about the occurences
 * @param stacks helper to delete the occurences
 * @param to_change: 7 = rr, 10 = rrr
 */
static void	ft_del_occurence(
	t_occurences list,
	t_stacks *stacks,
	int to_change)
{
	t_node	*tmp;
	t_node	*tmp2;
	int		i;

	if (list.list1.amount <= list.list2.amount && list.list1.amount > 0
		&& list.list2.amount > 0)
	{
		tmp = list.list1.node;
		i = list.list1.amount;
		while (tmp && i > 0)
		{
			tmp2 = tmp->next;
			ft_node_delone(tmp, stacks->sort_sequence);
			i--;
			tmp = tmp2;
		}
		tmp = list.list2.node;
		while (tmp && list.list1.amount-- > 0)
		{
			tmp->value = to_change;
			tmp = tmp->next;
		}
	}
	else
		ft_del_occu_part2(list, stacks);
}

/**
 * *loop through the sort sequence and sanitize it
 * @param option 0 = ra and rb, 1 = rra and rrb
 * @param node: node to start the loop
 * @param stacks: helper to delete the occurences
 * @return node containing the node after the occurence of sanitization
*/
static t_node	*ft_loop_occurence(int option, t_node *node, t_stacks *stacks)
{
	t_occurences	list;
	t_node			*tmp;

	if (option == 0)
		list = ft_init_occurences(0);
	else if (option == 1)
		list = ft_init_occurences(1);
	else
		ft_putstr_fd("Error in option assignation: ft_loop_occurence\n", 2);
	tmp = node;
	while (tmp && (tmp->value == list.list1.key
			|| tmp->value == list.list2.key))
	{
		if (list.list1.amount == 0 && tmp->value == list.list1.key)
			list.list1.node = tmp;
		else if (list.list2.amount == 0 && tmp->value == list.list2.key)
			list.list2.node = tmp;
		if (tmp->value == list.list1.key)
			list.list1.amount++;
		if (tmp->value == list.list2.key)
			list.list2.amount++;
		tmp = tmp->next;
	}
	ft_del_occurence(list, stacks, list.new_instru);
	return (tmp);
}

/**
 * *Sanitize sort sequence
 * @infos: check for list of ra and rb, and rra and rrb
 * according to the amount of following list, print them as rr or rrr
 * @infos: limit.min : store the min value of the list,
 * limit.max : store the amount of elements in the list
 * @param stacks
 */
void	ft_sanitize_sequence(t_stacks *stacks)
{
	t_node			*tmp;

	tmp = stacks->sort_sequence->head;
	while (tmp)
	{
		if (tmp->value == 5 || tmp->value == 6)
		{
			tmp = ft_loop_occurence(0, tmp, stacks);
		}
		else if (tmp->value == 8 || tmp->value == 9)
		{
			tmp = ft_loop_occurence(1, tmp, stacks);
		}
		else
			if (tmp)
				tmp = tmp->next;
	}
}
