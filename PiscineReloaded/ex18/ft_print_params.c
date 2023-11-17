/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:09:43 by rcutte            #+#    #+#             */
/*   Updated: 2023/11/01 15:22:03 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include<unistd.h>
void ft_putchar(char c)
{
	write(1, &c, 1);
}
*/
void	ft_putchar(char c);

int	main(int ac, char **av)
{
	int	i;
	int	k;

	k = 1;
	i = 0;
	while (k != ac)
	{
		while (av[k][i])
		{
			ft_putchar(av[k][i]);
			i++;
		}
		ft_putchar('\n');
		i = 0;
		k++;
	}
	return (0);
}
