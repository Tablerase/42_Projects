/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:34:58 by rcutte            #+#    #+#             */
/*   Updated: 2024/04/19 17:59:22 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_MATERIA_H_
#define A_MATERIA_H_

#include <iostream>
#include "../include/Character.hpp"

class ICharacter;

class AMateria
{
  protected:
    std::string type_;

  public:
    AMateria();
    AMateria(std::string const & type);
    AMateria(const AMateria &other);
    AMateria &operator=(const AMateria &other);
    virtual ~AMateria();
    
    std::string const & getType() const; //Returns the materia type
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};

#endif
