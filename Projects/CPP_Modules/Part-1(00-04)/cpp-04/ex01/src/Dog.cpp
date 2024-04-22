/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:26:06 by rcutte            #+#    #+#             */
/*   Updated: 2024/04/17 23:59:28 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"

/* ===================== Constructor / Destructor =========================== */

Dog::Dog() : Animal("Dog") {
  std::cout << BLUB << "🐶 Constructor Dog by default" << RESET << "\n";
  this->brain_ = new Brain();
}

Dog::~Dog(){
  if (this->brain_ != NULL)
    delete this->brain_;
  std::cout << BLKB << "🐶 Destructor Dog by default" << RESET << "\n";
}

Dog::Dog(const Dog &other) : Animal(other) {
  std::cout << BLUB << "🐶 Constructor Dog by copy" << RESET << "\n";
  *this = other;
}

Dog &Dog::operator=(const Dog &rhs){
  std::cout << BLUB << "🐶 Constructor Dog by assign" << RESET << "\n";
  if (this != &rhs) {
    this->type_ = rhs.type_;
    this->brain_ = new Brain(*rhs.brain_);
  }
  return *this;
}

/* ============================== Functions ================================= */

void Dog::makeSound() const {
  std::cout << "🐶 Wouf 🐕 Wouf !" << "\n";
}

/* =============================== Getter =================================== */


/* =============================== Output =================================== */

