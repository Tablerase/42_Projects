/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:35:07 by rcutte            #+#    #+#             */
/*   Updated: 2023/10/30 14:57:08 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>

void	ft_putchar(char c);
void	ft_print_alphabet(void);
/*
void	ft_putchar(char c)
{
	write(1, &c, 1);
}*/

void	ft_print_alphabet(void)
{
	int	alpha;

	alpha = 97;
	while (alpha <= 122)
	{
		ft_putchar(alpha);
		alpha++;
	}
}
/*
#include <stdio.h>

int main() 

{
	ft_print_alphabet();
	return (0);
}
*/
