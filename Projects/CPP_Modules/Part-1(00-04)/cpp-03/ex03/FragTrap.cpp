/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 23:20:31 by rcutte            #+#    #+#             */
/*   Updated: 2024/04/16 22:40:01 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
  : ClapTrap("NoNameFrag", 100, 100, 30),
    hit_point_(100),
    attack_dmg_(30) {
  std::cout << CYNHB << "Constructor of FragTrap default Called" << RESET << "\n";
};
FragTrap::~FragTrap(){
  std::cout << BLKHB << "Destructor of FragTrap Called" << RESET << "\n";
};

FragTrap::FragTrap(std::string name)
  : ClapTrap(name, 100, 100, 30),
    hit_point_(100),
    attack_dmg_(30) {
  std::cout << CYNHB << "Constructor of FragTrap name param Called" << RESET << "\n";
}

FragTrap::FragTrap(
  std::string name, 
  int hitpoint, 
  int energy_point, 
  int attack_dmg)
  : ClapTrap(name, hitpoint, energy_point, attack_dmg), hit_point_(hitpoint),
  attack_dmg_(attack_dmg) {
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

/* ---------------------------- Getter/Setter ------------------------------- */

int FragTrap::getHitPoint(){
  return this->hit_point_;
}

int FragTrap::getAttackDmg(){
  return this->attack_dmg_;
}

void FragTrap::setHitPoint(int amount){
  if (amount > 0){
    this->hit_point_ = amount;
  }
  else
    this->hit_point_ = 0;
}

void FragTrap::setAttackDmg(int amount){
  if (amount > 0){
    this->attack_dmg_ = amount;
  }
  else
    this->attack_dmg_ = 0;
}