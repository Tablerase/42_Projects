/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:26:55 by rcutte            #+#    #+#             */
/*   Updated: 2024/04/14 20:47:28 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

int main()
{
  ClapTrap player_1("Clapper");
  std::cout
    << WHTB << std::setw(30) << std::setfill('=') 
    << "[INFO]" << std::setw(30)
    << RESET << std::setfill(' ') << "\n";

  std::cout << player_1;

  std::cout
      << WHTB << std::setw(30) << std::setfill('=') 
      << "[BATTLE INFO]" << std::setw(30) 
      << RESET << std::setfill(' ') << "\n";
  player_1.attack("Dummy");
  player_1.takeDamage(2);
  player_1.beRepaired(3);

  std::cout
    << WHTB << std::setw(30) << std::setfill('=') 
    << "[INFO]" << std::setw(30)
    << RESET << std::setfill(' ') << "\n";
  std::cout << player_1;
}