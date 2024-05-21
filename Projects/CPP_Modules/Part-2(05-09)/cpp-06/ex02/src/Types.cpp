/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Types.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:13:45 by rcutte            #+#    #+#             */
/*   Updated: 2024/05/20 16:35:25 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Types.hpp"

/* ======================== Constructor / Destructor ======================== */

Base::~Base(){}

/* =============================== Functions ================================ */

/**
 * @note It randomly instanciates A, B or C and returns the instance
 * as a Base pointer.
*/
Base* generate(void){
  int random = rand() % 3; // generate random num in range 0 to 2.
  switch (random)
  {
  case 0:
    return new A();
  case 1:
    return new B();
  case 2:
    return new C();
  default:
    break;
  }
  return new A(); // protect non void function return
}

static void TypeMessage(std::string type){
  std::cout
    << BLUB << "Type" << RESET << " ";
  if (type == "A"){
    std::cout << GRNB << " " << type << " " << RESET << "\n";
  } else if (type == "B") {
    std::cout << MAGB << " " << type << " " << RESET << "\n";
  } else {
    std::cout << YELB << " " << type << " " << RESET << "\n";
  }
}

/**
 * @note It prints the actual type of the object pointed to by p: 
 * "A", "B" or "C"
*/
void identify(Base* p){
  A *a_ptr = dynamic_cast<A*>(p);
  if (a_ptr != NULL){
    return TypeMessage("A");
  }
  B *b_ptr = dynamic_cast<B*>(p);
  if (b_ptr != NULL){
    return TypeMessage("B");
  }
  C *c_ptr = dynamic_cast<C*>(p);
  if (c_ptr != NULL){
    return TypeMessage("C");
  }
}

/**
 * @note It prints the actual type of the object pointed to by p: 
 * "A", "B" or "C". Using a pointer inside this function is forbidden.
 * Try and catch because a ref cant be NULL.
*/
void identify(Base& p){
  try {
    A a_ref = dynamic_cast<A&>(p);
    return TypeMessage("A");
  } catch (std::exception &e){
    try {
      B b_ref = dynamic_cast<B&>(p);
      return TypeMessage("B");
    } catch (std::exception &e){
      try {
        C c_ref = dynamic_cast<C&>(p);
        return TypeMessage("C");
      } catch (std::exception &e){
        std::cout
          << REDB << "ERROR" << RESET << " "
          << BRED << e.what() << RESET << "\n";
      }
    }
  }
}
