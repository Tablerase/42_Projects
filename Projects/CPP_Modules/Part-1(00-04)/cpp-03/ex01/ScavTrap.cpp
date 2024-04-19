/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 20:55:31 by rcutte            #+#    #+#             */
/*   Updated: 2024/04/14 23:17:03 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("NoNameScav", 100, 50, 20){
  std::cout << CYNHB << "Constructor of ScavTrap default Called" << RESET << "\n";
};

ScavTrap::~ScavTrap(){
  std::cout << BLKHB << "Destructor of ScavTrap Called" << RESET << "\n";
};

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20){
  std::cout << CYNHB << "Constructor of ScavTrap name param Called" << RESET << "\n";
}

ScavTrap::ScavTrap(
  std::string name, 
  int hitpoint, 
  int energy_point, 
  int attack_dmg)
  : ClapTrap(name, hitpoint, energy_point, attack_dmg) {
  std::cout << CYNHB << "Constructor of ScavTrap full param Called" << RESET << "\n";
}

ScavTrap::ScavTrap(ScavTrap &obj) : ClapTrap(obj.getName() + " [copy]"){
  *this = obj;
  std::cout << CYNHB << "Constructor of ScavTrap copy Called" << RESET << "\n";
}

ScavTrap &ScavTrap::operator=(ScavTrap &rhs){
  this->setHitPoint(rhs.getHitPoint());
  this->setEnergyPoint(rhs.getEnergyPoint());
  this->setAttackDmg(rhs.getAttackDmg());
  std::cout << CYNHB << "Constructor of ScavTrap assign Called" << RESET << "\n";
  return *this;
}

// Functions overide

void ScavTrap::attack(const std::string &target){
  if (this->getEnergyPoint() > 0)
  {
    this->setEnergyPoint(this->getEnergyPoint() - 1);
    std::cout 
      << REDB << "ATTACK Derived" << RESET << " "
      << BBLU << this->getName() << RESET
      << " => " << BRED << target << RESET
      << ", generating " << BRED << this->getAttackDmg()
      << RESET << " points of damage !" << "\n";
  }
}

// Functions

void ScavTrap::guardGate(){
  std::cout
    << MAGHB << "GATE" << RESET << " " << BBLU << this->getName()
    << RESET << " is in Gate Keeper Mode"
    << "\n";
}