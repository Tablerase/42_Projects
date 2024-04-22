/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:05:58 by rcutte            #+#    #+#             */
/*   Updated: 2024/04/17 22:48:15 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Wrong on purpose to show how error occurs

#include "../include/WrongAnimal.hpp"

/* ===================== Constructor / Destructor =========================== */

WrongAnimal::WrongAnimal() : type_("Default Type") {
  std::cout << BLUB << "🐻 Constructor WrongAnimal by default" << RESET << "\n";
}

WrongAnimal::~WrongAnimal(){
  std::cout << BLKB << "🐻 Destructor WrongAnimal by default" << RESET << "\n";
}

WrongAnimal::WrongAnimal(std::string type) : type_(type) {
  std::cout << BLUB << "🐻 Constructor WrongAnimal by param" << RESET << "\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &obj){
  *this = obj;
  std::cout << BLUB << "🐻 Constructor WrongAnimal by copy" << RESET << "\n";
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rhs){
  this->type_ = rhs.type_;
  std::cout << BLUB << "🐻 Constructor WrongAnimal by assign" << RESET << "\n";
  return *this;
}

void WrongAnimal::makeSound() const {
  std::cout << "🐻 Default Wrong Sound" << "\n";
}

/* =============================== Getter =================================== */

std::string WrongAnimal::getType() const {
  return this->type_;
}

/* =============================== Output =================================== */

std::ostream &operator<<(std::ostream &os, WrongAnimal &obj){
  os
    << "type: " << BLU << obj.getType()
    << RESET << "\n";
  return os;
}