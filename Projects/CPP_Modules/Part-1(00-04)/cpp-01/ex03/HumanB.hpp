/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 18:03:37 by rcutte            #+#    #+#             */
/*   Updated: 2024/04/08 18:37:30 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HUMANB_H_
#define HUMANB_H_

#include "Weapon.hpp"

class HumanB
{
private:
  std::string name_;
  Weapon *item_;
public:
  HumanB(std::string name);

  ~HumanB();

  void setWeapon(Weapon *item);

  void attack();
};

#endif