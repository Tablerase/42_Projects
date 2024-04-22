/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:26:06 by rcutte            #+#    #+#             */
/*   Updated: 2024/04/17 22:47:22 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"

/* ===================== Constructor / Destructor =========================== */

Dog::Dog() : Animal("Dog") {
  std::cout << BLUB << "🐶 Constructor Dog by default" << RESET << "\n";
}

Dog::~Dog(){
  std::cout << BLKB << "🐶 Destructor Dog by default" << RESET << "\n";
}

Dog::Dog(const Dog &obj) : Animal(obj) {
  *this = obj;
  std::cout << BLUB << "🐶 Constructor Dog by copy" << RESET << "\n";
}

Dog &Dog::operator=(const Dog &rhs){
  this->type_ = rhs.type_;
  std::cout << BLUB << "🐶 Constructor Dog by assign" << RESET << "\n";
  return *this;
}

/* ============================== Functions ================================= */

void Dog::makeSound() const {
  std::cout << "🐶 Wouf 🐕 Wouf !" << "\n";
}

/* =============================== Getter =================================== */


/* =============================== Output =================================== */

