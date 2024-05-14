/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:29:21 by rcutte            #+#    #+#             */
/*   Updated: 2024/05/14 14:19:05 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(){
  this->levels[0] = "DEBUG";
  this->levels[1] = "INFO";
  this->levels[2] = "WARNING";
  this->levels[3] = "ERROR";
}
Harl::~Harl(){}

void Harl::debug(){
  std::cerr
    << BMAG << "[ DEBUG ]" << RESET
    << "\n I love having extra bacon 🥓 for my 7XL-double-cheese-triple-pickle-special-ketchup burger 🍔. I really do !"
    << "\n\n";
}

void Harl::info(){
  std::cout
    << BCYN << "[ INFO ]" << RESET
    << "\n I cannot believe adding extra bacon 🥓 costs more money 💲. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !"
    << "\n\n";
}

void Harl::warning(){
  std::cerr
    << BYEL << "[ WARNING ]" << RESET
    << "\n I think I deserve to have some extra bacon 🥓🥓 for free. I’ve been coming for years 👴 whereas you started working here since last month."
    << "\n\n";
}

void Harl::error(){
   std::cerr
    << BRED << "[ ERROR ]" << RESET
    << "\n This is unacceptable ! 😠💢 I want to speak to the manager now."
    << "\n\n";
}

int Harl::getMinComplain(){
  return this->min_complain_lvl_;
}

/**
 * @brief Index of the complain
 * @return Index if found, -1 in case of error/not found
*/
int Harl::getIndexLvL(std::string input){
  int i = 0;
  while (i < this->amount_of_levels)
  {
    if (levels[i].compare(input) == 0)
      break;
    i++;
  }
  if (i >= amount_of_levels){ return -1; }
  return i;
}

bool Harl::setMinComplain(std::string input){
  int i = getIndexLvL(input);
  if (i == -1)
  {
    std::cerr
      << BRED << "[ Probably complaining about insignificant problems ]"
      << RESET << "\n";
    return false;
  }
  this->min_complain_lvl_ = i;
  return true;
}

void Harl::complain(std::string level){
  enum complain_lvl {
    DEBUG,
    INFO,
    WARNING,
    ERROR
  };

  int index = this->getIndexLvL(level);
  if (index < this->min_complain_lvl_)
    return;

  switch (index)
  {
    case DEBUG:
      this->debug();
      break;

    case INFO:
      this->info();
      break;
    
    case WARNING:
      this->warning();
      break;

    case ERROR:
      this->error();
      break;

    default:
      std::cerr << "Invalid Input" << "\n";
      break;
  }
}
