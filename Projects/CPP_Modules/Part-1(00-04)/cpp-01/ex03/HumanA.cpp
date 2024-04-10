/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:43:23 by rcutte            #+#    #+#             */
/*   Updated: 2024/04/08 18:42:17 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &item)
  : name_(name), item_(item) {}

HumanA::~HumanA(){}

void HumanA::attack(){
  std::cout 
    << BBLU << this->name_ << RESET 
    << " attacks with their "
    << BMAG << this->item_.getType() << RESET
    << "\n";
}
