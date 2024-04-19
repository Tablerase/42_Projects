/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:26:55 by rcutte            #+#    #+#             */
/*   Updated: 2024/04/16 21:40:32 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
  ClapTrap player_a("Claper");
  ScavTrap player_b("Scaver");
  FragTrap player_c("Frager");
  DiamondTrap player_d("Diamonder");
  
  std::cout
    << WHTB << std::setw(30) << std::setfill('=') 
    << "[INFO]" << std::setw(30)
    << RESET << std::setfill(' ') << "\n";

  std::cout << player_a;
  std::cout << player_b;
  std::cout << player_c;
  std::cout << player_d;

  std::cout
      << WHTB << std::setw(30) << std::setfill('=') 
      << "[BATTLE INFO]" << std::setw(30) 
      << RESET << std::setfill(' ') << "\n";
  player_a.attack("Dummy 0");
  player_a.takeDamage(2);
  player_a.beRepaired(3);
  player_b.attack("Dummy");
  player_b.takeDamage(2);
  player_b.beRepaired(3);
  player_b.guardGate();
  player_c.attack("Dumb Dummy");
  player_c.takeDamage(2);
  player_c.beRepaired(3);
  player_c.highFivesGuys();
  player_d.attack("Dummy 2");
  player_d.takeDamage(20);
  player_d.beRepaired(5);
  player_d.whoAmI();
  player_d.guardGate();
  player_d.highFivesGuys();

  std::cout
    << WHTB << std::setw(30) << std::setfill('=') 
    << "[INFO]" << std::setw(30)
    << RESET << std::setfill(' ') << "\n";
  std::cout << player_b;
  std::cout << player_d;
}