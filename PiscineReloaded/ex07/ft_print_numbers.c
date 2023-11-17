/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:59:00 by rcutte            #+#    #+#             */
/*   Updated: 2023/10/30 15:08:06 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
void	ft_print_numbers(void);

void	ft_print_numbers(void)
{
	int	num;

	num = 48;
	while (num <= 57)
	{
		ft_putchar(num);
		num++;
	}
}
/*
#include <unistd.h>
void	ft_putchar(char c){
	write(1, &c, 1);
}

int main() {
	ft_print_numbers();	
    return 0;
}
*/
