/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 23:20:31 by rcutte            #+#    #+#             */
/*   Updated: 2024/04/14 23:44:31 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("NoNameFrag", 100, 100, 30){
  std::cout << CYNHB << "Constructor of FragTrap default Called" << RESET << "\n";
};
FragTrap::~FragTrap(){
  std::cout << BLKHB << "Destructor of FragTrap Called" << RESET << "\n";
};

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30){
  std::cout << CYNHB << "Constructor of FragTrap name param Called" << RESET << "\n";
}

FragTrap::FragTrap(
  std::string name, 
  int hitpoint, 
  int energy_point, 
  int attack_dmg)
  : ClapTrap(name, hitpoint, energy_point, attack_dmg) {
  std::cout << CYNHB << "Constructor of FragTrap full param Called" << RESET << "\n";
}

FragTrap::FragTrap(FragTrap &obj) : ClapTrap(obj.getName() + " [copy]") {
  *this = obj;
  std::cout << CYNHB << "Constructor of FragTrap copy Called" << RESET << "\n";
};

FragTrap &FragTrap::operator=(FragTrap &rhs){
  this->setHitPoint(rhs.getHitPoint());
  this->setEnergyPoint(rhs.getEnergyPoint());
  this->setAttackDmg(rhs.getAttackDmg());
  std::cout << CYNHB << "Constructor of FragTrap assign Called" << RESET << "\n";
  return *this;
}

void FragTrap::highFivesGuys(void){
  std::cout
    << MAG << this->getName() << " : 🤚LET'S HIGHT FIVE🤚"
    << RESET << "\n";
}