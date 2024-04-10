/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:29:21 by rcutte            #+#    #+#             */
/*   Updated: 2024/04/09 18:41:03 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(){}
Harl::~Harl(){}

void Harl::debug(){
  std::cerr
    << BMAG << "[ DEBUG ]" << RESET
    << "\n I love having extra bacon 🥓 for my 7XL-double-cheese-triple-pickle-special-ketchup burger 🍔. I really do !"
    << "\n";
}

void Harl::info(){
  std::cout
    << BCYN << "[ INFO ]" << RESET
    << "\n I cannot believe adding extra bacon 🥓 costs more money 💲. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !"
    << "\n";
}

void Harl::warning(){
  std::cerr
    << BYEL << "[ WARNING ]" << RESET
    << "\n I think I deserve to have some extra bacon 🥓🥓 for free. I’ve been coming for years 👴 whereas you started working here since last month."
    << "\n";
}

void Harl::error(){
   std::cerr
    << BRED << "[ ERROR ]" << RESET
    << "\n This is unacceptable ! 😠💢 I want to speak to the manager now."
    << "\n";
}

void Harl::complain(std::string level){
  bool found = false;

  for (int i = 0; i < this->amount_of_levels; i++)
  {
    if (levels[i].compare(level) == 0) {
      (this->*functionArray[i])();
      found = true;
      break;
    }
  }

  if (found == false)
  {
    std::cerr
      << BRED << "Invalid Complain : " << RESET << level << "\n"
      << BYEL << "Available: DEBUG, INFO, WARNING, ERROR" << RESET << "\n";
  }
}
