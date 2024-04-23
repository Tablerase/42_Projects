/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:09:06 by rcutte            #+#    #+#             */
/*   Updated: 2024/04/18 00:15:51 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H_
# define CAT_H_

#include "../include/Animal.hpp"
#include "../include/Brain.hpp"

class Cat : public Animal {
  private:
    Brain *brain_;

  public:
    Cat();
    Cat(const Cat &other);
    virtual ~Cat();
    Cat &operator=(const Cat &rhs);

    virtual void makeSound() const;
};

#endif