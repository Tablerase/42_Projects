/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 17:07:56 by rcutte            #+#    #+#             */
/*   Updated: 2024/01/15 12:13:10 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/Includes/libft.h"
# include <stdlib.h>

// Structures

typedef struct s_limits
{
	int	min;
	int	max;
}	t_limits;

typedef struct s_medians
{
	int	median1;
	int	median2;
	int	median3;
	int	median4;
	int	median5;
	int	median6;
	int	median7;
	int	median8;
	int	median9;
	int	median10;
	int	median11;
	int	median12;
}	t_medians;

typedef struct s_node
{
	int				value;
	unsigned int	moves;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node		*head;
	int			size;
	t_limits	limits;
}	t_stack;

/**
 * *t_stacks
 * @param a: stack a
 * @param b: stack b
 * @param sort_sequence: stack containing all the moves
*/
typedef struct s_stacks
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*sort_sequence;
}	t_stacks;

/**
 * *Occurence of one of the following: ra, rb, rra, rrb
 * @param pos: position of the first occurence
 * @param key: key of the first occurence (5: ra, 6: rb, 8: rra, 9: rrb)
 * @param occurence: amount of occurence
*/
typedef struct s_occurence
{
	void	*node;
	int		key;
	int		amount;
}	t_occurence;

/**
 * *Occurences of one of the following: ra, rb, rra, rrb
 * @param list1: occurences of ra or rra
 * @param list2: occurences of rb or rrb
 * @param new_instru: intro to replace the occurences(7: rr, 10: rrr)
*/
typedef struct s_occurences
{
	t_occurence	list1;
	t_occurence	list2;
	int			new_instru;
}	t_occurences;

// Nodes

t_node			*ft_node_new(int value);
void			ft_node_add_last(t_stack *stack, int value);
void			ft_node_add_first(t_stack *stack, int value);
void			ft_node_del_last(t_stack *stack);
void			ft_node_del_first(t_stack *stack);
void			ft_node_delone(t_node *node, t_stack *stack);

// Node Utils

unsigned int	ft_stack_size(t_stack *stack);
int				ft_stack_min(t_stack *stack);
int				ft_stack_max(t_stack *stack);
int				ft_top_part(t_stacks *stacks, int number, int options);

// Stacks

t_stacks		*ft_init_stacks(int ac, char **av);
t_stack			*ft_new_stack(void);
t_stack			*ft_duplicate_stack(t_stack *stack);
t_stacks		*ft_duplicate_stacks(t_stacks *stacks);

// Sort

void			ft_sort_swap(t_stack *stack, t_stacks *stacks);
void			ft_sort_swap_both(t_stacks *stacks);
void			ft_sort_push_a(t_stacks *stacks);
void			ft_sort_push_b(t_stacks *stacks);
void			ft_sort_rotate(t_stack *stack, t_stacks *stacks);
void			ft_sort_rotate_both(t_stacks *stacks);
void			ft_sort_reverse_rotate(t_stack *stack, t_stacks *stacks);
void			ft_sort_reverse_rotate_both(t_stacks *stacks);

// Sort Utils

int				ft_is_sorted(t_stack *stack);
void			ft_choose_sorter(t_stacks *stacks, char *sorter);
void			ft_sort_select(t_stacks *stacks, int amount);
int				*ft_sort_array(t_stack *stack);
int				*ft_get_array(t_stack *stack);
	// Sort Few

void			ft_sort_two(t_stacks *stacks);
void			ft_sort_three(t_stacks *stacks);
void			ft_sort_five(t_stacks *stacks);

// Sort Many

void			ft_sort_many(t_stacks *stacks);
t_medians		ft_init_medians(t_stacks *stacks);

// Sort Big

void			ft_sort_big(t_stacks *stacks);
t_medians		ft_init_medians_big(t_stacks *stacks);

// Arguments

void			ft_check_args(int ac, char **av, int splitted);
char			**ft_split_argument(char const *s, char c);
int				ft_split_size(char **strs);
void			ft_free_split(char **strs);

// Mem Manager

void			ft_free_stack(t_stack *stack);
void			ft_free_stacks(t_stacks *stacks);

// Error

void			ft_exit_error(t_stacks *stacks, char *msg);

// Print

void			ft_print_sort_sequence(t_stacks *stacks);
void			ft_sanitize_sequence(t_stacks *stacks);

// Debug

void			ft_print_stacks(t_stacks *stacks);
void			ft_print_stacks_moves(t_stacks *stacks);
void			ft_print_int_array(int *array, unsigned int size);

// Math

unsigned int	ft_abs(int number);
int				ft_min(int a, int b, int c, int d);

#endif