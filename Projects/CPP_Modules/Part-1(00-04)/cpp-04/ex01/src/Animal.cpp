/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 13:23:08 by rcutte            #+#    #+#             */
/*   Updated: 2024/04/17 23:47:41 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"

/* ===================== Constructor / Destructor =========================== */

Animal::Animal() : type_("Default Type") {
  std::cout << BLUB << "🐾 Constructor Animal by default" << RESET << "\n";
}

Animal::~Animal(){
  std::cout << BLKB << "🐾 Destructor Animal by default" << RESET << "\n";
}

Animal::Animal(std::string type) : type_(type) {
  std::cout << BLUB << "🐾 Constructor Animal by param" << RESET << "\n";
}

Animal::Animal(const Animal &obj){
  *this = obj;
  std::cout << BLUB << "🐾 Constructor Animal by copy" << RESET << "\n";
}

Animal &Animal::operator=(const Animal &rhs){
  if (this != &rhs) {
    this->type_ = rhs.type_;
  }
  std::cout << BLUB << "🐾 Constructor Animal by assign" << RESET << "\n";
  return *this;
}

void Animal::makeSound() const {
  std::cout << "🐾 Default Sound" << "\n";
}

/* =============================== Getter =================================== */

std::string Animal::getType() const {
  return this->type_;
}

/* =============================== Output =================================== */

std::ostream &operator<<(std::ostream &os, Animal &obj){
  os
    << "type: " << BLU << obj.getType()
    << RESET << "\n";
  return os;
}