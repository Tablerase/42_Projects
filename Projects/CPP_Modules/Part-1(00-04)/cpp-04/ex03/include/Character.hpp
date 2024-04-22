/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:54:50 by rcutte            #+#    #+#             */
/*   Updated: 2024/04/22 00:53:44 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_H_
#define CHARACTER_H_

#include <iostream>
#include <iomanip>
#include "../include/color.h"
#include "../include/ICharacter.hpp"
#include "../include/AMateria.hpp"

class Character : virtual public ICharacter
{
  private:
    std::string name_;
    int         materias_slots_;
    AMateria    **materias_;
    int         garbages_amount_;
    AMateria    **garbages_;

  public:
    Character();
    Character(const std::string name);
    Character(const Character &other);
    Character &operator=(const Character &other);
    virtual ~Character();

    virtual std::string const &getName() const ;

    void AddInGarbages(AMateria *garbage);

    virtual void equip(AMateria* m);
    virtual void unequip(int idx);
    virtual void use(int idx, ICharacter& target);
};

std::ostream &operator<<(std::ostream &os, const Character &obj);

#endif