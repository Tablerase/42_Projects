/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:23:56 by rcutte            #+#    #+#             */
/*   Updated: 2024/04/16 18:39:07 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_H_
# define DIAMONDTRAP_H_

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
  private:
    const std::string name_;

  public:
    DiamondTrap();
    DiamondTrap(std::string name);
    DiamondTrap(DiamondTrap &obj);
    DiamondTrap &operator=(DiamondTrap &rhs);
    virtual ~DiamondTrap();

    // Function
    void whoAmI();

    // Overide
    virtual void attack(const std::string& target);

    // Getter (only way to access diamond name instead of clap name)
    virtual std::string getName();
};

std::ostream &operator<<(std::ostream &os, DiamondTrap &obj);

#endif