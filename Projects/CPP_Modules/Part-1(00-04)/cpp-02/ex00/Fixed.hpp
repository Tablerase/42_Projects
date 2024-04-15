/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:11:40 by rcutte            #+#    #+#             */
/*   Updated: 2024/04/11 15:37:14 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FIXED_H_
# define FIXED_H_

#include <iostream>
#include "color.h"

class Fixed 
{
private:
  int in_int_;
  const static int bits_ = 8;
public:
  Fixed();
  Fixed(const Fixed &obj);
  Fixed &operator=(const Fixed &obj);
  ~Fixed();
  
  int getRawBits( void ) const;
  void setRawBits( int const raw );
};

#endif