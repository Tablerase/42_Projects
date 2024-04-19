/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:26:55 by rcutte            #+#    #+#             */
/*   Updated: 2024/04/14 23:44:20 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"
#include "ClapTrap.hpp"

int main()
{
  ClapTrap player_1("Clapper");
  ClapTrap copy_1(player_1);
  FragTrap player_2("Frager");
  FragTrap copy_2(player_2);
  
  std::cout
    << WHTB << std::setw(30) << std::setfill('=') 
    << "[INFO]" << std::setw(30)
    << RESET << std::setfill(' ') << "\n";

  std::cout << player_1;
  std::cout << copy_1;
  std::cout << player_2;
  std::cout << copy_2;

  std::cout
      << WHTB << std::setw(30) << std::setfill('=') 
      << "[BATTLE INFO]" << std::setw(30) 
      << RESET << std::setfill(' ') << "\n";
  player_1.attack("Dummy");
  player_1.takeDamage(2);
  player_1.beRepaired(3);
  player_2.attack("Dummy 2");
  player_2.takeDamage(20);
  player_2.beRepaired(5);
  player_2.highFivesGuys();

  std::cout
    << WHTB << std::setw(30) << std::setfill('=') 
    << "[INFO]" << std::setw(30)
    << RESET << std::setfill(' ') << "\n";
  std::cout << player_1;
  std::cout << player_2;
}