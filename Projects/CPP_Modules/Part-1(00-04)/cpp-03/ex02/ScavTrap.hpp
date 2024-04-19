/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 20:55:27 by rcutte            #+#    #+#             */
/*   Updated: 2024/04/16 21:51:03 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H_
# define SCAVTRAP_H_

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
  public:
    ScavTrap();
    ScavTrap(std::string name);
    ScavTrap(std::string name, int hitpoint, int energy_point, int attack_dmg);
    ScavTrap(ScavTrap &obj);
    ScavTrap &operator=(ScavTrap &rhs);
    virtual ~ScavTrap();

    // overide
    virtual void attack(const std::string &target);

    // functions
    void guardGate();
};

#endif
