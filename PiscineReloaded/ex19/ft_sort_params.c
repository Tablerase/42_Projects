/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:24:38 by rcutte            #+#    #+#             */
/*   Updated: 2023/11/01 17:28:11 by rcutte           ###   ########.fr       */
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

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (*(s1 + i) == *(s2 + i) && *(s1 + i) != '\0')
	{
		i++;
	}
	return (*(s1 + i) - *(s2 + i));
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
	{
		ft_putchar(*(str + i));
		i++;
	}
}

void	ft_swap(char **s1, char **s2)
{
	char	*temp;

	temp = *s1;
	*s1 = *s2;
	*s2 = temp;
}

void	ft_sort(int size, char **list)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (ft_strcmp(list[i], list[j]) < 0)
			{
				ft_swap(&list[i], &list[j]);
			}
			j++;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	int	k;

	k = 1;
	if (ac > 1)
		ft_sort(ac - 1, av + 1);
	else
		return (0);
	while (k != ac)
	{
		ft_putstr(av[k]);
		ft_putchar('\n');
		k++;
	}
	return (0);
}
