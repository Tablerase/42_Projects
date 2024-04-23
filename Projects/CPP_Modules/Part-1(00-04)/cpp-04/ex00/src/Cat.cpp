/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:09:08 by rcutte            #+#    #+#             */
/*   Updated: 2024/04/17 22:47:00 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"

/* ===================== Constructor / Destructor =========================== */

Cat::Cat() : Animal("Cat") {
  std::cout << BLUB << "🐱 Constructor Cat by default" << RESET << "\n";
}

Cat::~Cat(){
  std::cout << BLKB << "🐱 Destructor Cat by default" << RESET << "\n";
}

Cat::Cat(const Cat &obj) : Animal(obj) {
  *this = obj;
  std::cout << BLUB << "🐱 Constructor Cat by copy" << RESET << "\n";
}

Cat &Cat::operator=(const Cat &rhs){
  this->type_ = rhs.type_;
  std::cout << BLUB << "🐱 Constructor Cat by assign" << RESET << "\n";
  return *this;
}

/* ============================== Functions ================================= */

void Cat::makeSound() const {
  std::cout << "🐱 Meow 🐈 Meow !" << "\n";
}

/* =============================== Getter =================================== */


/* =============================== Output =================================== */

