/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:34:49 by rcutte            #+#    #+#             */
/*   Updated: 2024/04/22 16:18:32 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Character.hpp"

/* ===================== Constructor / Destructor =========================== */

Character::Character() : name_("Cloud") {
  this->materias_slots_ = 4;
  this->materias_ = new AMateria*[materias_slots_];
  for (int i = 0; i < materias_slots_; i++){
    materias_[i] = NULL;
  }
  this->garbages_amount_ = 0;
  this->garbages_ = new AMateria*[garbages_amount_];
  #ifdef LOG
  std::cout << BLUB << "🧙‍ Constructor Character by default" << RESET << "\n";
  #endif
}

Character::~Character(){
  for (int i = 0; i < materias_slots_; i++) {
    if (this->materias_[i] != NULL)
      delete this->materias_[i];
  }
  delete [] this->materias_;
  for (int i = 0; i < this->garbages_amount_; i++){
    if (this->garbages_[i] != NULL)
      delete this->garbages_[i];
  }
  delete[] this->garbages_;
  #ifdef LOG
  std::cout << BLKB << "🧙‍ Destructor Character by default" << RESET << "\n";
  #endif
}

Character::Character(const std::string name) : name_(name) {
  this->materias_slots_ = 4;
  this->materias_ = new AMateria*[materias_slots_];
  for (int i = 0; i < materias_slots_; i++){
    materias_[i] = NULL;
  }
  this->garbages_amount_ = 0;
  this->garbages_ = new AMateria*[garbages_amount_];
  #ifdef LOG
  std::cout << BLUB << "🧙‍ Constructor Character by param" << RESET << "\n";
  #endif
}

Character::Character(const Character &other){
  *this = other;
  #ifdef LOG
  std::cout << BLUB << "🧙‍ Constructor Character by copy" << RESET << "\n";
  #endif
}

Character &Character::operator=(const Character &other){
  if (this != &other) {
    // Check to know if lhs is init or empty
    if (this->name_.empty() == false) {
      // Delete old data
      for (int i = 0; i < this->materias_slots_; i++){
        if (this->materias_[i] != NULL){
          delete this->materias_[i];
          this->materias_[i] = NULL;
        }
      }
      delete[] this->materias_;
      for (int i = 0; i < this->garbages_amount_; i++){
        if (this->garbages_[i] != NULL){
          delete this->garbages_[i];
          this->garbages_[i] = NULL;
        }
      }
      delete[] this->garbages_;
    }
    // Add new data
    this->name_ = other.name_;
    this->materias_slots_ = other.materias_slots_;
    this->materias_ = new AMateria*[this->materias_slots_];
    for (int i = 0; i < this->materias_slots_; i++){
      if (other.materias_[i] != NULL)
        this->materias_[i] = other.materias_[i]->clone();
      else
        this->materias_[i] = NULL;
    }
    this->garbages_amount_ = other.garbages_amount_;
    this->garbages_ = new AMateria*[this->garbages_amount_];
    for (int i = 0; i < this->garbages_amount_; i++){
      if (other.garbages_[i] != NULL)
        this->garbages_[i] = other.garbages_[i]->clone();
      else
        this->garbages_[i] = NULL;
    }
  }
  #ifdef LOG
  std::cout << BLUB << "🧙‍ Constructor Character by assign" << RESET << "\n";
  #endif
  return *this;
}

/* =============================== Getter =================================== */

std::string const &Character::getName() const {
  return this->name_;
}

/* ============================== Functions ================================= */

void Character::equip(AMateria* m){
  for (int i = 0; i < this->materias_slots_; i++){
    if (materias_[i] == NULL) {
      this->materias_[i] = m;
      std::cout
        << MAGB << this->getName() << RESET << " equip "
        << BMAG << m->getType() << RESET << " materia\n";
      return;
    }
  }
  #ifdef LOG
  std::cout << "No slot to store " << BMAG << m->getType() << RESET
    << "\n";
  #endif
  delete m;
}

void Character::AddInGarbages(AMateria *garbage){
  int old_garbage_amount = this->garbages_amount_;
  this->garbages_amount_++;
  AMateria **tmp_garbages = new AMateria*[this->garbages_amount_];
  // Copy new garbage collector
  for (int i = 0; i < this->garbages_amount_; i++){
    if (i >= old_garbage_amount) {
      tmp_garbages[i] = garbage;
    }
    else
      tmp_garbages[i] = this->garbages_[i]->clone();
  }
  // Delete previous garbage collector
  for (int i = 0; i < old_garbage_amount; i++){
    if (this->garbages_[i] != NULL){
      delete this->garbages_[i];
    }
  }
  delete[] this->garbages_;
  // Assign new garbage collector
  this->garbages_ = tmp_garbages;
}

void Character::unequip(int idx){
  int i = 0;
  while (i < this->materias_slots_)
  {
    if (i == idx && this->materias_[i] != NULL) {
      std::cout
        << "Unequip " << BRED << this->materias_[i]->getType()
        << RESET << " at slot " << BRED << idx << RESET << "\n";
      this->AddInGarbages(this->materias_[i]);
      this->materias_[i] = NULL;
      break;
    }
    i++;
  }
  if (i >= this->materias_slots_)
    std::cout << "Materia Slot: "
    << BRED << idx << RESET << " unavailable" << "\n";
}

void Character::use(int idx, ICharacter& target){
  int i = 0;
  while (i < this->materias_slots_)
  {
    if (i == idx && this->materias_[i] != NULL) {
      this->materias_[i]->use(target);
      return;
    }
    i++;
  }
  if (i >= this->materias_slots_)
    std::cout << "Materia Slot: "
    << BRED << idx << RESET << " unavailable" << "\n";
}

/* =============================== Output =================================== */

std::ostream &operator<<(std::ostream &os, const Character &obj){
  os
    << "Character: " << BLU << obj.getName()
    << RESET << "\n";
  return os;
}
