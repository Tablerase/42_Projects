/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:11:44 by rcutte            #+#    #+#             */
/*   Updated: 2023/11/02 18:30:02 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include  <unistd.h>
void	ft_putchar(char c)
{
	write(1, &c, 1);
}
*/
void	ft_putchar(char c);

void	ft_is_negative(int n)
{
	if (n < 0)
	{
		ft_putchar('N');
	}
	else
	{
		ft_putchar('P');
	}
}

/*
int main() {
	ft_is_negative(-5);
    return 0;
}
*/
