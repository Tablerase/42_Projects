/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:09:08 by rcutte            #+#    #+#             */
/*   Updated: 2024/04/18 00:17:21 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"

/* ===================== Constructor / Destructor =========================== */

Cat::Cat() : Animal("Cat") {
  std::cout << BLUB << "🐱 Constructor Cat by default" << RESET << "\n";
  this->brain_ = new Brain();
}

Cat::~Cat(){
  if (this->brain_ != NULL)
    delete this->brain_;
  std::cout << BLKB << "🐱 Destructor Cat by default" << RESET << "\n";
}

Cat::Cat(const Cat &other) : Animal(other) {
  std::cout << BLUB << "🐱 Constructor Cat by copy" << RESET << "\n";
  *this = other;
}

Cat &Cat::operator=(const Cat &rhs){
  std::cout << BLUB << "🐱 Constructor Cat by assign" << RESET << "\n";
  if (this != &rhs) {
    this->type_ = rhs.type_;
    this->brain_ = new Brain(*rhs.brain_);
  }
  return *this;
}

/* ============================== Functions ================================= */

void Cat::makeSound() const {
  std::cout << "🐱 Meow 🐈 Meow !" << "\n";
}

/* =============================== Getter =================================== */


/* =============================== Output =================================== */

