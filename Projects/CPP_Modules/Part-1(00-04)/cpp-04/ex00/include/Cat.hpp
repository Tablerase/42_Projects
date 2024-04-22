/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:09:06 by rcutte            #+#    #+#             */
/*   Updated: 2024/04/17 22:46:42 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H_
# define CAT_H_

#include "../include/Animal.hpp"

class Cat : public Animal {
  public:
    Cat();
    Cat(const Cat &obj);
    virtual ~Cat();
    Cat &operator=(const Cat &rhs);

    virtual void makeSound() const;
};

#endif