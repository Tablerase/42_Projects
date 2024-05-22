/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:08:18 by rcutte            #+#    #+#             */
/*   Updated: 2024/05/21 16:50:53 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H_
#define ARRAY_H_

# include <iostream>
# include <iomanip>
# include <typeinfo>
# include <stdexcept>
# include "color.h"

template <typename T>
class Array
{
public:
  // Constructors / Destructor

  Array() : array_(NULL), length_(0) { array_ = new T[0];}
  Array(unsigned int n) : array_(new T[n]), length_(n) {
    for (unsigned int i = 0; i < length_; ++i) {
      array_[i] = 0;
    }
  }
  Array(const Array &other) :
    array_(new T[other.length_]), length_(other.length_) {
    for (unsigned int i = 0; i < length_; ++i) {
      array_[i] = other.array_[i];
    }
  }
  ~Array() {
    delete[] array_;
  }

  // Operators
  
  Array &operator=(const Array &rhs) {
    if (this != &rhs) {
      delete[] array_;
      array_ = new T[rhs.length_];
      length_ = rhs.length_;
      for (unsigned int i = 0; i < length_; ++i) {
        array_[i] = rhs.array_[i];
      }
    }
    return *this;
  }
  T &operator[](unsigned int index) {
    if (index >= length_) {
      throw std::out_of_range("Array index out of range");
    }
    return array_[index];
  }

  // Getter

  unsigned int size() const {
    return length_;
  };

private:
  T *array_;
  unsigned int length_;
};

template <typename T>
std::ostream &operator<<(std::ostream &os, Array<T> &obj){
  os
    << BLUB << "Array" << RESET << " type: "
    << BBLU << typeid(T).name() << RESET << "\n"
    << BBLU << "----------- value -----------" << RESET << "\n";
  for (unsigned int i = 0; i < obj.size(); i++){
    os << obj[i] << "\n";
  }
  return os;
}

#endif