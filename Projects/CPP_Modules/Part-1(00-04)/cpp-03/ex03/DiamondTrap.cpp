/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:23:50 by rcutte            #+#    #+#             */
/*   Updated: 2024/04/16 22:39:33 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
  : ClapTrap(),
    ScavTrap(),
    FragTrap(),
    name_("NoNameDiamond")
{
  // this->hit_point_ = 100;
  // this->energy_point_ = 50;
  // this->attack_dmg_ = 30;
  std::cout << CYNHB << "Constructor of 💎 DiamondTrap default Called" << RESET << "\n";
}

DiamondTrap::~DiamondTrap(){
  std::cout << BLKHB << "Destructor of 💎 DiamondTrap Called" << RESET << "\n";
}

DiamondTrap::DiamondTrap(std::string name)
  : ClapTrap(name + "_clap_name"), name_(name) {
  // this->hit_point_ = 100;
  // this->energy_point_ = 50;
  // this->attack_dmg_ = 30;
  std::cout << CYNHB << "Constructor of 💎 DiamondTrap name param Called" << RESET << "\n";
}

DiamondTrap::DiamondTrap(DiamondTrap &obj)
  : ClapTrap(obj),
    ScavTrap(obj),
    FragTrap(obj),
    name_(obj.getName() + "[copy]")
{
  *this = obj;
  std::cout << CYNHB << "Constructor of 💎 DiamondTrap copy Called" << RESET << "\n";
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap &rhs){
  this->setHitPoint(rhs.getHitPoint());
  this->setEnergyPoint(rhs.getEnergyPoint());
  this->setAttackDmg(rhs.getAttackDmg());
  std::cout << CYNB << "Constructor of 💎 DiamondTrap assign Called" << RESET << "\n";
  return *this;
}

// Functions

void DiamondTrap::whoAmI(){
  std::cout << CYNB << "WHOIAM" << RESET << " DiamondTrap: "
  << BLU << this->name_ << RESET << " ClapTrap: "
  << BLU << ClapTrap::name_ << RESET << "\n";
}

// Getter

std::string DiamondTrap::getName(){
  return this->name_;
}

// Overide

void DiamondTrap::attack(const std::string& target) {
  ScavTrap::attack(target);
}

// Output Overload (overide clap name)

std::ostream &operator<<(std::ostream &os, DiamondTrap &obj){
  os 
    << MAGB << "Diamond Status" << RESET << "\n"
    << std::setw(15) << "Name: " << BLU << obj.getName() << RESET << "\n"
    << std::setw(15) << "Hit Point: " << BLU << obj.getHitPoint() << RESET << "\n"
    << std::setw(15) << "Energy Point: " << BLU << obj.getEnergyPoint() << RESET << "\n"
    << std::setw(15) << "Attack dmg: " << BLU << obj.getAttackDmg() << RESET << "\n"
    ;
  return os;
}