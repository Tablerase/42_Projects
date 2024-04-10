/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:32:41 by rcutte            #+#    #+#             */
/*   Updated: 2024/04/08 18:39:08 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(){}

Weapon::Weapon(std::string type){
  this->type_ = type;
}

Weapon::~Weapon(){}

const std::string &Weapon::getType() {
  return this->type_;
}

void Weapon::setType(std::string type){
  this->type_ = type;
}
