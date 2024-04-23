/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:22:52 by rcutte            #+#    #+#             */
/*   Updated: 2024/04/17 22:47:32 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H_
# define DOG_H_

#include "../include/Animal.hpp"

class Dog : public Animal {
  public:
    Dog();
    Dog(const Dog &obj);
    virtual ~Dog();
    Dog &operator=(const Dog &rhs);

    virtual void makeSound() const;
};

#endif