/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:22:52 by rcutte            #+#    #+#             */
/*   Updated: 2024/04/17 23:10:22 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H_
# define DOG_H_

#include "../include/Animal.hpp"
#include "../include/Brain.hpp"

class Dog : public Animal {
  private:
    Brain *brain_;

  public:
    Dog();
    Dog(const Dog &other);
    virtual ~Dog();
    Dog &operator=(const Dog &rhs);

    virtual void makeSound() const;
};

#endif