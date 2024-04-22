/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 00:22:31 by rcutte            #+#    #+#             */
/*   Updated: 2024/04/22 01:43:01 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Ice.hpp"

/* ===================== Constructor / Destructor =========================== */

Ice::Ice() : AMateria("ice") {
  #ifdef LOG
  std::cout << BLUB << "🧊 Constructor Ice by default" << RESET << "\n";
  #endif
}

Ice::~Ice(){
  #ifdef LOG
  std::cout << BLKB << "🧊 Destructor Ice by default" << RESET << "\n";
  #endif
}

Ice::Ice(const Ice &obj) : AMateria("ice") {
  *this = obj;
  #ifdef LOG
  std::cout << BLUB << "🧊 Constructor Ice by copy" << RESET << "\n";
  #endif
}

Ice &Ice::operator=(const Ice &other){
  (void)other;
  std::cout << BRED << "Why would you do that ?" << RESET << "\n";
  #ifdef LOG
  std::cout << BLUB << "🧊 Constructor Ice by assign" << RESET << "\n";
  #endif
  return *this;
}

/* ============================== Functions ================================= */

void Ice::use(ICharacter &target){
  std::cout 
    << CYNB << "🧊* shoots an ice bolt at " << BRED
    << target.getName() << RESET << CYNB << " *🧊" << RESET << "\n";
}

AMateria *Ice::clone() const {
  AMateria *clonedIce = new Ice();
  return clonedIce;
}
