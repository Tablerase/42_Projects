/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:11:27 by rcutte            #+#    #+#             */
/*   Updated: 2024/04/11 15:37:00 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(){
  std::cout
    << GRNB << "Default constructor called"
    << RESET << "\n";
}

Fixed::~Fixed(){
  std::cout
    << YELB << "Destructor called"
    << RESET << "\n";
}

Fixed::Fixed(const Fixed &obj){
  std::cout
    << CYNB << "Copy constructor called"
    << RESET << "\n";

  *this = obj;
}

Fixed &Fixed::operator=(const Fixed &obj){
  std::cout
    << BLUB << "Copy assignement operator called"
    << RESET << "\n";
    
  if (this != &obj){
    this->in_int_ = obj.getRawBits();
  }
  return *this;
}

int Fixed::getRawBits( void ) const {
  std::cout
    << MAGB << "getRawBits called"
    << RESET << "\n";

  return this->in_int_;
}

void  Fixed::setRawBits( int const raw ){
  this->in_int_ = raw;
}
