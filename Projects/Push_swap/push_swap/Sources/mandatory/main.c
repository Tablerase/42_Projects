/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 17:02:26 by rcutte            #+#    #+#             */
/*   Updated: 2024/01/15 12:13:43 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

int	main(int ac, char **av)
{
	t_stacks	*stacks;
	char		**strs;
	int			splitted;

	splitted = 0;
	if (ac == 2)
	{
		strs = ft_split_argument(av[1], ' ');
		ac = ft_split_size(strs);
		splitted = 1;
	}
	else
		strs = av;
	ft_check_args(ac, strs, splitted);
	stacks = ft_init_stacks(ac, strs);
	ft_sort_select(stacks, ac - 1);
	ft_print_sort_sequence(stacks);
	if (splitted)
		ft_free_split(strs);
	ft_free_stacks(stacks);
	return (0);
}
