/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 13:15:20 by rcutte            #+#    #+#             */
/*   Updated: 2024/04/18 11:14:37 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H_
# define ANIMAL_H_

#include <iostream>
#include <iomanip>
#include "../include/color.h"

class Animal {
  protected:
    std::string type_;

  public:
    Animal();
    Animal(std::string type);
    Animal(const Animal &obj);
    virtual ~Animal();
    Animal &operator=(const Animal &rhs);

    virtual void makeSound() const = 0; // pure function (making class abstract)

    std::string getType() const;
};

std::ostream &operator<<(std::ostream &os, Animal &obj);

#endif