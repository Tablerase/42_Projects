/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:05:48 by rcutte            #+#    #+#             */
/*   Updated: 2023/11/02 16:33:46 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i;

	i = 0;
	while (i < length)
	{
		f(tab[i]);
		i++;
	}
}
/*
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	power(int x)
{
	int	puissance;

	puissance = 0;
	while (x != 0)
	{
		x = x / 10;
		puissance++;
	}
	return (puissance - 1);
}

int	power_10(int a)
{
	int	x;

	x = 1;
	while (a != 0)
	{
		x = x * 10;
		a--;
	}
	return (x);
}

int	boucle_print(int puissance, int number)
{
	int	i;
	int	puissance_10;

	while (puissance > 0)
	{
		puissance_10 = power_10(puissance);
		i = number / puissance_10;
		ft_putchar(i + '0');
		number = number % puissance_10;
		puissance--;
	}
	return (number);
}

void	ft_putnbr(int nb)
{
	int	number;
	int	puissance;

	number = nb;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		number = -nb;
	}
	puissance = power(number);
	number = boucle_print(puissance, number);
	if (number < 10)
		ft_putchar(number + '0');
}

int main() {
	int	list[4] = {10,35,40,50};
	ft_foreach(list, sizeof(list)/sizeof(int), ft_putnbr);
	return 0;
}
*/
