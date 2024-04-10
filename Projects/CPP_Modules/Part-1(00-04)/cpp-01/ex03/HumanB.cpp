/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 18:05:08 by rcutte            #+#    #+#             */
/*   Updated: 2024/04/08 18:40:37 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
  : name_(name){}

HumanB::~HumanB(){}

void HumanB::setWeapon(Weapon *item){
  this->item_ = item;
}

void HumanB::attack(){
  std::cout 
    << BCYN << this->name_ << RESET 
    << " attacks with their "
    << BMAG << this->item_->getType() << RESET
    << "\n";
}
