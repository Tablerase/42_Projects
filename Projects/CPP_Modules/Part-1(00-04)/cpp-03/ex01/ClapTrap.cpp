/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 14:57:50 by rcutte            #+#    #+#             */
/*   Updated: 2024/04/16 18:06:02 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
  : name_("NoNameClap"),
    hit_point_(10),
    energy_point_(10),
    attack_dmg_(0){
  std::cout << BLUB << "Constructor of ClapTrap default Called" << RESET << "\n";
}

ClapTrap::ClapTrap(std::string input_name)
  : name_(input_name),
    hit_point_(10),
    energy_point_(10),
    attack_dmg_(0){
  std::cout << BLUB << "Constructor of ClapTrap name param Called" << RESET << "\n";
}

ClapTrap::ClapTrap(
  std::string input_name,
  int hitpoint,
  int energy_point,
  int attack_dmg)
  : name_(input_name), hit_point_(hitpoint), energy_point_(energy_point),
  attack_dmg_(attack_dmg) {
  std::cout << BLUB << "Constructor of ClapTrap full param Called" << RESET << "\n";
}

ClapTrap::ClapTrap(const ClapTrap &obj)
  : name_(obj.name_ + " [copy]")
{
  *this = obj;
  std::cout << BLUB << "Constructor by copy of ClapTrap Called" << RESET << "\n";
}

ClapTrap::~ClapTrap(){
  std::cout << BLKB << "Destructor of ClapTrap Called" << RESET << "\n";
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs){
  hit_point_ = rhs.hit_point_;
  energy_point_ = rhs.energy_point_;
  attack_dmg_ = rhs.attack_dmg_;
  std::cout << BLUB << "Constructor by assign of ClapTrap Called" << RESET << "\n";
  return *this;
}

// Getter / Setter

std::string ClapTrap::getName(){
  return this->name_;
}

int ClapTrap::getHitPoint(){
  return this->hit_point_;
}

int ClapTrap::getEnergyPoint(){
  return this->energy_point_;
}

int ClapTrap::getAttackDmg(){
  return this->attack_dmg_;
}

void ClapTrap::setHitPoint(int amount){
  if (amount > 0){
    this->hit_point_ = amount;
  }
  else
    this->hit_point_ = 0;
}

void ClapTrap::setEnergyPoint(int amount){
  if (amount > 0){
    this->energy_point_ = amount;
  }
  else
    this->energy_point_ = 0;
}

void ClapTrap::setAttackDmg(int amount){
  if (amount > 0){
    this->attack_dmg_ = amount;
  }
  else
    this->attack_dmg_ = 0;
}

// Functions

void ClapTrap::attack(const std::string& target){
  if (this->getEnergyPoint() > 0)
  {
    this->setEnergyPoint(this->getEnergyPoint() - 1);
    std::cout 
      << REDB << "ATTACK" << RESET << " "
      << BBLU << this->getName() << RESET
      << " => " << BRED << target << RESET
      << ", causing " << BRED << this->getAttackDmg()
      << RESET << " points of damage !" << "\n";
  }
}

void ClapTrap::takeDamage(unsigned int amount){
  if (this->getHitPoint() - amount > 0)
  {
    this->setHitPoint(this->hit_point_ - amount);
    std::cout
    << YELB << "DAMAGE" << RESET << " "
    << BBLU << this->getName() << RESET
    << " took " << BYEL << amount << RESET " damage."
    << "\n";
  }
}

void ClapTrap::beRepaired(unsigned int amount){
  if (this->getHitPoint() > 0 && this->getEnergyPoint() > 0)
  {
    this->setHitPoint(this->hit_point_ + amount);
    this->setEnergyPoint(this->energy_point_ - 1);
    std::cout
    << GRNB << "REPAIR" << RESET << " "
    << BBLU << this->getName() << RESET
    << " restore " << BGRN << amount << RESET " hit point."
    << "\n";
  }
}

// Std output overload / Display instance info

std::ostream &operator<<(std::ostream &os, ClapTrap &obj){
  os 
    << MAGB << "Robot Status" << RESET << "\n"
    << std::setw(15) << "Name: " << BLU << obj.getName() << RESET << "\n"
    << std::setw(15) << "Hit Point: " << BLU << obj.getHitPoint() << RESET << "\n"
    << std::setw(15) << "Energy Point: " << BLU << obj.getEnergyPoint() << RESET << "\n"
    << std::setw(15) << "Attack dmg: " << BLU << obj.getAttackDmg() << RESET << "\n"
    ;
  return os;
}