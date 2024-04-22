/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:14:04 by rcutte            #+#    #+#             */
/*   Updated: 2024/04/17 22:49:56 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/WrongCat.hpp"

/* ===================== Constructor / Destructor =========================== */

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
  std::cout << BLUB << "🐱 Constructor WrongCat by default" << RESET << "\n";
}

WrongCat::~WrongCat(){
  std::cout << BLKB << "🐱 Destructor WrongCat by default" << RESET << "\n";
}

WrongCat::WrongCat(const WrongCat &obj) : WrongAnimal(obj) {
  *this = obj;
  std::cout << BLUB << "🐱 Constructor WrongCat by copy" << RESET << "\n";
}

WrongCat &WrongCat::operator=(const WrongCat &rhs){
  this->type_ = rhs.type_;
  std::cout << BLUB << "🐱 Constructor WrongCat by assign" << RESET << "\n";
  return *this;
}

/* ============================== Functions ================================= */

void WrongCat::makeSound() const {
  std::cout << "🐱 Meow 🐈 Meow !" << "\n";
}
