/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:27:26 by rcutte            #+#    #+#             */
/*   Updated: 2024/04/17 23:58:52 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Brain.hpp"

Brain::Brain() {
  this->amount_of_ideas = 100;
  this->ideas = new std::string[amount_of_ideas];
  std::cout << BLUB << "🧠 Constructor Brain by default" << RESET << "\n";
}

Brain::~Brain() {
  if (this->ideas != NULL)
    delete[] this->ideas;
  std::cout << BLKB << "🧠 Destructor Brain by default" << RESET << "\n";
}

Brain::Brain(const Brain& other) {
  this->amount_of_ideas = other.amount_of_ideas;
  this->ideas = new std::string[other.amount_of_ideas];
  std::copy(other.ideas, other.ideas + other.amount_of_ideas, this->ideas);
  std::cout << BLUB << "🧠 Constructor Brain by copy" << RESET << "\n";
}

Brain& Brain::operator=(const Brain &other) {
  if (this != &other) {
    if (this->ideas != NULL)
      delete[] this->ideas;
    this->amount_of_ideas = other.amount_of_ideas;
    this->ideas = new std::string[other.amount_of_ideas];
    std::copy(other.ideas, other.ideas + other.amount_of_ideas, this->ideas);
  }
  std::cout << BLUB << "🧠 Constructor Brain by assign" << RESET << "\n";
  return *this;
}

