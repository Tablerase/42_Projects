/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 10:57:09 by rcutte            #+#    #+#             */
/*   Updated: 2024/04/22 00:31:17 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_H_
#define ICE_H_

#include "../include/AMateria.hpp"

class Ice : public AMateria {
  public:
    Ice();
    virtual ~Ice();
    Ice(const Ice &obj);
    Ice &operator=(const Ice &other);

    virtual void use(ICharacter &target);
    virtual AMateria *clone() const;
};

#endif