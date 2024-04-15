/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:11:27 by rcutte            #+#    #+#             */
/*   Updated: 2024/04/12 01:39:28 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(){
  // std::cout
  //   << GRNB << "Default constructor called"
  //   << RESET << "\n";
}

/**
 * @brief Convert Integer into fixed point value
 * @note We bitshift by the amount of bits used to store
 * the floating / fractional part.
*/
Fixed::Fixed(const int number){
  // std::cout
  //   << GRNB << "Integer constructor called"
  //   << RESET << "\n";
  this->num_ = number << fract_bits_;
}

/**
 * @brief Convert Floating number into fixed point value
 * @note We use a fractional multiplicator to save the precision
 * that available in the amount of bits allocated to the fractional part
 * @note We round to save a little of precision
 * (because we can lose some precision 
 * if the space to store fractional part is small).
*/
Fixed::Fixed(const float number){
  // std::cout
  //   << GRNB << "Float constructor called"
  //   << RESET << "\n";
  this->num_ = roundf(number * this->fractional_multiplicator_);
}

Fixed::~Fixed(){
  // std::cout
  //   << YELB << "Destructor called"
  //   << RESET << "\n";
}

Fixed::Fixed(const Fixed &obj){
  // std::cout
  //   << CYNB << "Copy constructor called"
  //   << RESET << "\n";

  *this = obj;
}

int Fixed::getRawBits( void ) const {
  return this->num_;
}

void  Fixed::setRawBits( int const raw ){
  this->num_ = raw;
}

/**
 * @brief Convert Fixed Point to Floating Point
 * @note Revert back to float by doing opposite operation
*/
float Fixed::toFloat( void ) const {
  return (float)this->num_ / (float)this->fractional_multiplicator_;
}

int Fixed::toInt( void ) const {
  return this->num_ >> this->fract_bits_;
}

// Operators (rhs = right hand side, lhs = left hand side)

Fixed &Fixed::operator=(const Fixed &rhs){
  // std::cout
  //   << BLUB << "Copy assignement operator called"
  //   << RESET << "\n";
  if (this != &rhs){
    this->num_ = rhs.getRawBits();
  }
  return *this;
}

Fixed Fixed::operator+(const Fixed &rhs){
  return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(const Fixed &rhs){
  return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(const Fixed &rhs){
  return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(const Fixed &rhs){
  return Fixed(this->toFloat() / rhs.toFloat());
}

// Comparators

bool Fixed::operator==(const Fixed &rhs){
  return this->num_ == rhs.getRawBits();
}

bool Fixed::operator!=(const Fixed &rhs){
  return this->num_ != rhs.getRawBits();
}

bool Fixed::operator>(const Fixed &rhs){
  return this->num_ > rhs.getRawBits();
}

bool Fixed::operator>=(const Fixed &rhs){
  return this->num_ >= rhs.getRawBits();
}

bool Fixed::operator<(const Fixed &rhs){
  return this->num_ < rhs.getRawBits();
}

bool Fixed::operator<=(const Fixed &rhs){
  return this->num_ <= rhs.getRawBits();
}

// Incrementations

Fixed Fixed::operator++(){
  // this->num_ += 1 * this->fractional_multiplicator_; 
  this->num_ += 1; // incrementation before return
  return *this;
}

Fixed Fixed::operator++(int){
  Fixed tmp = *this; // copy of obj before incrementation
  // this->num_ += 1 * this->fractional_multiplicator_;
  this->num_ += 1;
  return tmp; // return not containing incrementation info
}

Fixed Fixed::operator--(){
  // this->num_ -= 1 * this->fractional_multiplicator_;
  this->num_ -= 1;
  return *this;
}

Fixed Fixed::operator--(int){
  Fixed tmp = *this;
  // this->num_ -= 1 * this->fractional_multiplicator_;
  this->num_ -= 1;
  return tmp;
}

// Extremity

Fixed Fixed::min(const Fixed &lhs,const Fixed &rhs){
  return lhs.getRawBits() < rhs.getRawBits() ? lhs : rhs;
}

Fixed Fixed::max(const Fixed &lhs,const Fixed &rhs){
  return lhs.getRawBits() > rhs.getRawBits() ? lhs : rhs;
}
