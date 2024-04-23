/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:05:52 by rcutte            #+#    #+#             */
/*   Updated: 2024/04/17 22:48:35 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Wrong on purpose to show how error occurs

#ifndef WRONG_ANIMAL_H_
# define WRONG_ANIMAL_H_

#include <iostream>
#include <iomanip>
#include "../include/color.h"

class WrongAnimal {
  protected:
    std::string type_;

  public:
    WrongAnimal();
    WrongAnimal(std::string type);
    WrongAnimal(const WrongAnimal &obj);
    ~WrongAnimal();
    WrongAnimal &operator=(const WrongAnimal &rhs);

    void makeSound() const;

    std::string getType() const;
};

std::ostream &operator<<(std::ostream &os, WrongAnimal &obj);

#endif