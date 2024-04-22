/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:11:48 by rcutte            #+#    #+#             */
/*   Updated: 2024/04/17 22:48:04 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_CAT_H_
# define WRONG_CAT_H_

#include "../include/WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
  public:
    WrongCat();
    WrongCat(const WrongCat &obj);
    ~WrongCat();
    WrongCat &operator=(const WrongCat &rhs);

    void makeSound() const;
};

#endif