/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:11:40 by rcutte            #+#    #+#             */
/*   Updated: 2024/04/11 17:37:53 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FIXED_H_
# define FIXED_H_

#include <iostream>
#include <cmath>
#include "color.h"

/*
Let's consider a 8-bit fixed-point binary number in <8,4> format.

| Decimal | Binary Fixed-Point |
|---------|-------------------|
| 0.0     | 0000 0000         |
| 0.5     | 0000 1000         |
| 1.0     | 0001 0000         |
| 1.5     | 0001 1000         |
| 2.0     | 0010 0000         |
| 2.5     | 0010 1000         |
| 3.0     | 0011 0000         |
| 3.5     | 0011 1000         |

Note: This table assumes 8-bit fixed-point binary representation 
in <8,4> format. The binary values are approximations.

In this exercice we are in <64, 8>
*/

class Fixed
{
private:
  int num_;
  const static int fract_bits_ = 8;
  const static int fractional_multiplicator_ = 1 << fract_bits_;
public:
  Fixed();
  Fixed(const Fixed &obj);
  Fixed(const int number);
  Fixed(const float number);
  Fixed &operator=(const Fixed &obj);
  ~Fixed();
  
  int getRawBits( void ) const;
  void setRawBits( int const raw );
  float toFloat( void ) const;
  int toInt ( void ) const;
};

static std::ostream &operator<<(std::ostream &os, const Fixed &obj){
  os << obj.toFloat();
  return os;
}

#endif