/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:04:09 by rcutte            #+#    #+#             */
/*   Updated: 2024/01/13 17:05:06 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

/**
 * *Sort an int array - Bubble sort
 * @param stack: stack to sort
 * @param size: size of the stack
 */
static void	ft_sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	int				tmp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[j] < tab[i])
			{
				tmp = tab[j];
				tab[j] = tab[i];
				tab[i] = tmp;
			}
			j++;
		}
		i++;
	}
}

/**
 * *Sort an array
 * @infos: Sorting using bubble sort
 * @param stack to sort
 * @return int array
 */
int	*ft_sort_array(t_stack *stack)
{
	int				*array;
	unsigned int	i;
	t_node			*tmp;

	i = 0;
	tmp = stack->head;
	array = malloc(sizeof(int) * ft_stack_size(stack));
	if (array == NULL)
		return (ft_putstr_fd("Mem error sorted int array", 2), NULL);
	while (tmp)
	{
		array[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
	ft_sort_int_tab(array, ft_stack_size(stack));
	return (array);
}

/**
 * *Get an array of int from stack
 * @infos: Transform stack into array
 * @param stack to transform into array
 * @return array of int
*/
int	*ft_get_array(t_stack *stack)
{
	int				*array;
	unsigned int	i;
	t_node			*tmp;

	i = 0;
	tmp = stack->head;
	array = malloc(sizeof(int) * ft_stack_size(stack));
	if (!array)
		return (ft_putstr_fd("Malloc error for int array", 2), NULL);
	while (tmp)
	{
		array[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
	return (array);
}
