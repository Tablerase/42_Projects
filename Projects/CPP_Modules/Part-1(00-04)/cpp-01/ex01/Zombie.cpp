/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:36:25 by rcutte            #+#    #+#             */
/*   Updated: 2024/04/08 16:35:56 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(){
  this->name_ = "Zombie";
  std::cout << BBLU << "💀 Rising From the Dead 💀" << RESET << "\n";
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

void Zombie::setName(std::string name){
  this->name_ = name;
}

void Zombie::annonce(){
  std::cout << BGRN << "🧟 " << this->name_ << ": BraiiiiiiinnnzzzZ... 🧠" << RESET << "\n";
}
