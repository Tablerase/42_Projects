/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:43:32 by rcutte            #+#    #+#             */
/*   Updated: 2024/04/08 18:02:51 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HUMANA_H_
#define HUMANA_H_

#include "Weapon.hpp"

class HumanA
{
private:
  std::string name_;
  Weapon &item_;
public:
  HumanA(std::string name, Weapon &item);

  ~HumanA();

  void attack();
};



#endif