/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 14:57:46 by rcutte            #+#    #+#             */
/*   Updated: 2024/04/16 22:12:07 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H_
# define CLAPTRAP_H_

#include <iostream>
#include <iomanip>
#include "color.h"

class ClapTrap
{
protected:
  const std::string name_;
  int hit_point_;
  int energy_point_;
  int attack_dmg_;
public:
  ClapTrap();
  
  ClapTrap(std::string input_name);
  ClapTrap(std::string name, int hitpoint, int energy_point, int attack_dmg);
  ClapTrap(const ClapTrap &obj);
  virtual ~ClapTrap();

  ClapTrap  &operator=(const ClapTrap &rhs);

  virtual std::string getName();
  virtual int getHitPoint();
  virtual int getEnergyPoint();
  virtual int getAttackDmg();
  virtual void setHitPoint(int amount);
  virtual void setEnergyPoint(int amount);
  virtual void setAttackDmg(int amount);

  virtual void attack(const std::string& target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
};

std::ostream &operator<<(std::ostream &os, ClapTrap &obj);

#endif