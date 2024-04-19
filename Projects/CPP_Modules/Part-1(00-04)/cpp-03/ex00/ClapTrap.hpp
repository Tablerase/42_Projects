/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 14:57:46 by rcutte            #+#    #+#             */
/*   Updated: 2024/04/16 18:08:56 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H_
# define CLAPTRAP_H_

#include <iostream>
#include <iomanip>
#include "color.h"

class ClapTrap
{
private:
  const std::string name_;
  int hit_point_;
  int energy_point_;
  int attack_dmg_;
public:
  ClapTrap();
  ClapTrap(std::string input_name);
  ClapTrap(const ClapTrap &obj);
  ~ClapTrap();

  ClapTrap  &operator=(const ClapTrap &rhs);

  std::string getName();
  int getHitPoint();
  int getEnergyPoint();
  int getAttackDmg();
  void setHitPoint(int amount);
  void setEnergyPoint(int amount);
  void setAttackDmg(int amount);

  void attack(const std::string& target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
};

std::ostream &operator<<(std::ostream &os, ClapTrap &obj);

#endif