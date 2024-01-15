/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 11:09:21 by rcutte            #+#    #+#             */
/*   Updated: 2024/01/15 10:48:53 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

/**
 * *Create a new empty stack
 * @params: stack size
 * @return: a new stack
 */
t_stack	*ft_new_stack(void)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (new == NULL)
	{
		ft_putstr_fd("Error in mem alloc for stack struct\n", 2);
		return (NULL);
	}
	new->size = 0;
	new->limits.min = 0;
	new->limits.max = 0;
	new->head = NULL;
	return (new);
}

/**
 * *Fill the stack with the arguments
 * @params: stack, ac, av
 * Create a node when stack is empty
 */
static void	ft_fill_stack(t_stack *stack, int ac, char **av)
{
	int	i;

	i = 1;
	if (!stack->head)
	{
		stack->head = ft_node_new(ft_atoi(av[i]));
		i++;
	}
	while (i < ac)
	{
		ft_node_add_last(stack, ft_atoi(av[i]));
		i++;
	}
}

/**
 * *Initialize the stacks
 * @params: ac, av
 */
t_stacks	*ft_init_stacks(int ac, char **av)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_stack		*sort_sequence;
	t_stacks	*stacks;

	stacks = malloc(sizeof(t_stacks));
	if (stacks == NULL)
	{
		ft_putstr_fd("Error in mem alloc for stacks struct\n", 2);
		exit(EXIT_FAILURE);
	}
	stack_a = ft_new_stack();
	if (stack_a == NULL)
		return (exit(EXIT_FAILURE), NULL);
	stack_b = ft_new_stack();
	if (stack_b == NULL)
		return (free(stack_a), exit(EXIT_FAILURE), NULL);
	sort_sequence = ft_new_stack();
	if (sort_sequence == NULL)
		return (free(stack_a), free(stack_b), exit(EXIT_FAILURE), NULL);
	ft_fill_stack(stack_a, ac, av);
	stacks->a = stack_a;
	stacks->b = stack_b;
	stacks->sort_sequence = sort_sequence;
	return (stacks);
}

/**
 * *Calculate the medians from stack a and store them in a struct
 * @infos: The medians are calculated by dividing the stack size by 6,
 * then we get the value of the array at the index of the size divided by 6
 * from the sorted array (6 medians - best amount of pivots for 100 numbers)
 * @param stacks: stacks to sort
 * @return t_medians struct
 */
t_medians	ft_init_medians(t_stacks *stacks)
{
	t_medians		medians;
	int				*array;
	unsigned int	size;

	array = ft_sort_array(stacks->a);
	size = ft_stack_size(stacks->a);
	size = size / 6;
	medians.median1 = array[size];
	medians.median2 = array[size * 2];
	medians.median3 = array[size * 3];
	medians.median4 = array[size * 4];
	medians.median5 = array[size * 5];
	medians.median6 = array[ft_stack_size(stacks->a) - 1];
	free(array);
	return (medians);
}

/**
 * *Calculate the medians from stack a and store them in a struct
 * @infos: The medians are calculated by dividing the stack size by 12,
 * then we get the value of the array at the index of the size divided by 12
 * from the sorted array (12 medians - to be able to respect norm)
 * @fix: possibility to create a array of int to store 
 * a variable amount of medians
 * @param stacks: stacks to sort
 * @return t_medians struct
 */
t_medians	ft_init_medians_big(t_stacks *stacks)
{
	t_medians		medians;
	int				*array;
	unsigned int	size;

	array = ft_sort_array(stacks->a);
	size = ft_stack_size(stacks->a);
	size = size / 12;
	medians.median1 = array[size];
	medians.median2 = array[size * 2];
	medians.median3 = array[size * 3];
	medians.median4 = array[size * 4];
	medians.median5 = array[size * 5];
	medians.median6 = array[size * 6];
	medians.median7 = array[size * 7];
	medians.median8 = array[size * 8];
	medians.median9 = array[size * 9];
	medians.median10 = array[size * 10];
	medians.median11 = array[size * 11];
	medians.median12 = array[ft_stack_size(stacks->a) - 1];
	free(array);
	return (medians);
}
