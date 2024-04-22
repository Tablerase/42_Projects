/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 23:29:46 by rcutte            #+#    #+#             */
/*   Updated: 2024/04/22 17:02:36 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/MateriaSource.hpp"

/* ===================== Constructor / Destructor =========================== */

MateriaSource::MateriaSource() {
  this->source_slots_ = 4;
  this->source_ = new AMateria*[source_slots_];
  this->source_name_ = "Materia Source";
  for (int i = 0; i < source_slots_; i++){
    source_[i] = NULL;
  }
  #ifdef LOG
  std::cout << BLUB << "📚 Constructor MateriaSource by default" << RESET << "\n";
  #endif
}

MateriaSource::~MateriaSource(){
  for (int i = 0; i < this->source_slots_; i++) {
    if (this->source_[i] != NULL)
      delete this->source_[i];
  }
  delete [] this->source_;
  #ifdef LOG
  std::cout << BLKB << "📚 Destructor MateriaSource by default" << RESET << "\n";
  #endif
}

MateriaSource::MateriaSource(const MateriaSource &obj){
  *this = obj;
  #ifdef LOG
  std::cout << BLUB << "📚 Constructor MateriaSource by copy" << RESET << "\n";
  #endif
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other){
  if (this != &other) {
    if (this->source_name_.empty() == false) {
      // Delete old data
      for (int i = 0; i < this->source_slots_; i++){
        if (this->source_[i] != NULL){
          delete this->source_[i];
          this->source_[i] = NULL;
        }
      }
      delete[] this->source_;
    }
    // Add new data
    this->source_name_ = other.source_name_;
    this->source_slots_ = other.source_slots_;
    this->source_ = new AMateria*[source_slots_];
    for (int i = 0; i < this->source_slots_; i++){
      if (other.source_[i] != NULL)
        this->source_[i] = other.source_[i]->clone();
    }
  }
  #ifdef LOG
  std::cout << BLUB << "📚 Constructor MateriaSource by assign" << RESET << "\n";
  #endif
  return *this;
}

/* ============================== Functions ================================= */

void MateriaSource::learnMateria(AMateria *tolearn){
  for (int i = 0; i < this->source_slots_; i++) {
    if (source_[i] == NULL) {
      this->source_[i] = tolearn;
      return;
    }
  }
  #ifdef LOG
  std::cout << "No slot to store " << BMAG << tolearn->getType() << RESET
    << " in materia source\n";
  #endif 
  delete tolearn;
}

AMateria *MateriaSource::createMateria(const std::string &type){
  for (int i = 0; i < this->source_slots_; i++) {
    if (this->source_[i] != NULL) {
      if (this->source_[i]->getType().compare(type) == 0) {
        return this->source_[i]->clone();
      }
    }
  }
  return 0;
}
