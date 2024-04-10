/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:36:25 by rcutte            #+#    #+#             */
/*   Updated: 2024/04/08 15:16:26 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(){
  this->name_ = "InYourHead";
}

Zombie::~Zombie(){
  std::cout << BYEL << "🧟 " << this->name_ << ": Has been slained" << RESET << "\n";
}

Zombie::Zombie(std::string name)
{
  this->name_ = name;
  std::cout 
    << BGRN << "🧟 "
    << this->name_
    << ": Nice to meet you, that a nice brain you have."
    << RESET << "\n";
}


void Zombie::annonce(){
  std::cout << BGRN << "🧟 " << this->name_ << ": BraiiiiiiinnnzzzZ... 🧠" << RESET << "\n";
}
