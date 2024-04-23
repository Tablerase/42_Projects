/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:34:51 by rcutte            #+#    #+#             */
/*   Updated: 2024/04/22 01:34:23 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AMateria.hpp"

/* ===================== Constructor / Destructor =========================== */

AMateria::AMateria() : type_("Default Type") {
  #ifdef LOG
  std::cout << BLUB << "🪄 Constructor AMateria by default" << RESET << "\n";
  #endif
}

AMateria::~AMateria(){
  #ifdef LOG
  std::cout << BLKB << "🪄 Destructor AMateria by default" << RESET << "\n";
  #endif
}

AMateria::AMateria(const std::string &type) : type_(type) {
  #ifdef LOG
  std::cout << BLUB << "🪄 Constructor AMateria by param" << RESET << "\n";
  #endif
}

AMateria::AMateria(const AMateria &obj){
  *this = obj;
  #ifdef LOG
  std::cout << BLUB << "🪄 Constructor AMateria by copy" << RESET << "\n";
  #endif
}

AMateria &AMateria::operator=(const AMateria &other){
  if (this != &other) {
    this->type_ = other.type_;
  }
  #ifdef LOG
  std::cout << BLUB << "🪄 Constructor AMateria by assign" << RESET << "\n";
  #endif
  return *this;
}

/* ============================== Functions ================================= */

void AMateria::use(ICharacter &target){
  if (this->getType().compare("ice") == 0) {
    this->use(target);
  }
  else if (this->getType().compare("cure") == 0) {
    this->use(target);
  }
  else {
    std::cout
      << YELB << "❓* Unknown Attack directed to "
      << BLUB << target.getName() << RESET << YELB << " *❓"
      << RESET << "\n";
  }
}

/* =============================== Getter =================================== */

std::string const &AMateria::getType() const {
  return this->type_;
}
