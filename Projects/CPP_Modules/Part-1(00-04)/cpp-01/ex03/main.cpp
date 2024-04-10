/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:29:52 by rcutte            #+#    #+#             */
/*   Updated: 2024/04/08 18:38:18 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{

  {
    std::cout << WHTB << "Test HumanA:" << RESET << "\n";
    Weapon club = Weapon("crude spiked club");
    HumanA bob("Bob", club);
    bob.attack();
    club.setType("some other type of club");
    bob.attack();
  }
  {
    std::cout << WHTB << "Test HumanB:" << RESET << "\n";
    Weapon club = Weapon("crude spiked club");
    HumanB jim("Jim");
    jim.setWeapon(&club);
    jim.attack();
    club.setType("some other type of club");
    jim.attack();
  }
  return 0;
}