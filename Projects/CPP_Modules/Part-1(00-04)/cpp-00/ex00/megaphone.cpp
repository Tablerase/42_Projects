/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 12:40:11 by rcutte            #+#    #+#             */
/*   Updated: 2024/05/15 18:27:05 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>

void	shout(std::string str)
{
	for (int i = 0; str[i]; i++)
	{
		str[i] = std::toupper(str[i]);
	}
	std::cout << str;
}

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << "\n";
		return (EXIT_FAILURE);
	}

	int	i = 1;
	while (av[i])
	{
		shout(av[i]);
		i++;
	}
  std::cout << "\n";
	return (EXIT_SUCCESS);
}
