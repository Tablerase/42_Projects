/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 10:57:13 by rcutte            #+#    #+#             */
/*   Updated: 2024/04/22 00:55:35 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_H_
#define CURE_H_

#include "../include/AMateria.hpp"

class Cure : public AMateria {
  public:
    Cure();
    virtual ~Cure();
    Cure(const Cure &obj);
    Cure &operator=(const Cure &other);

    virtual void use(ICharacter &target);
    virtual AMateria *clone() const;
};

#endif