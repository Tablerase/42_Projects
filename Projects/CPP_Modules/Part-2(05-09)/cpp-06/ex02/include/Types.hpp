/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Types.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:15:08 by rcutte            #+#    #+#             */
/*   Updated: 2024/05/20 16:09:02 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_HPP
# define TYPES_HPP

# include <iostream>
# include <exception>
# include <iomanip>
# include <cstdlib>
# include <ctime>
# include "color.h"

// ! Orthodox Canonical Form not required

class Base
{
public:
  virtual ~Base();
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif