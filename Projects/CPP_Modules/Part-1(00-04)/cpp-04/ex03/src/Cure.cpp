/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 00:55:44 by rcutte            #+#    #+#             */
/*   Updated: 2024/04/22 01:48:18 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cure.hpp"

/* ===================== Constructor / Destructor =========================== */

Cure::Cure() : AMateria("cure") {
  #ifdef LOG
  std::cout << BLUB << "💚 Constructor Cure by default" << RESET << "\n";
  #endif
}

Cure::~Cure(){
  #ifdef LOG
  std::cout << BLKB << "💚 Destructor Cure by default" << RESET << "\n";
  #endif
}

Cure::Cure(const Cure &obj) : AMateria("cure") {
  *this = obj;
  #ifdef LOG
  std::cout << BLUB << "💚 Constructor Cure by copy" << RESET << "\n";
  #endif
}

Cure &Cure::operator=(const Cure &other){
  (void)other;
  std::cout << BRED << "Why would you do that ?" << RESET << "\n";
  #ifdef LOG
  std::cout << BLUB << "💚 Constructor Cure by assign" << RESET << "\n";
  #endif
  return *this;
}

/* ============================== Functions ================================= */

void Cure::use(ICharacter &target){
  std::cout 
      << GRNB << "💚* heals " << BRED
      << target.getName() << RESET << GRNB << "'s wounds *💚"
      << RESET << "\n";
}

AMateria *Cure::clone() const {
  AMateria *clonedCure = new Cure();
  return clonedCure;
}