/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Object.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:30:57 by rcutte            #+#    #+#             */
/*   Updated: 2024/06/23 14:58:38 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ================================  Header ================================= */

#include "Object.hpp"

/* ======================== Constructor / Destructor ======================== */

Object::Object(/* args */)
{
  #ifdef LOG
  std::cout << BLUB << "📘 Constructor Object by default" << RESET << "\n";
  #endif
}

Object::Object(const Object &other)
{
  *this = other;
  #ifdef LOG
  std::cout << BLUB << "📘 Constructor Pmerge by copy" << RESET << "\n";
  #endif
}

Object::~Object(){
  #ifdef LOG
  std::cout << BLKB << "📘‍ Destructor Object by default" << RESET << "\n";
  #endif
}

/* ================================ Operator ================================ */

Object &Object::operator=(Object const &rhs)
{
  #ifdef LOG
  std::cout << BLUB << "📘 Constructor Object by assign" << RESET << "\n";
  #endif
  if (this != &rhs){
    /* Code */
  }
  return *this;
}

/* ================================= Getter ================================= */



/* ================================= Setter ================================= */



/* ================================ Function ================================ */



/* ================================ Exception =============================== */



/* ================================= Output ================================= */

std::ostream &operator<<(std::ostream &os, const Object &obj){
  os
    << MAGB << "Object infos"
    << RESET << "\n";
  return os;
}