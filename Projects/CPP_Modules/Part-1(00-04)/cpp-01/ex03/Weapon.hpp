/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:32:43 by rcutte            #+#    #+#             */
/*   Updated: 2024/04/08 18:39:02 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WEAPON_H_
#define WEAPON_H_

#include <iostream>
#include <string>

#include "color.h"

class Weapon
{
private:
  std::string type_;
public:
  Weapon();
  Weapon(std::string type);
  ~Weapon();

  const std::string &getType();
  void setType(std::string type);
};



#endif