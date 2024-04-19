/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 23:20:29 by rcutte            #+#    #+#             */
/*   Updated: 2024/04/16 21:49:45 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H_
# define FRAGTRAP_H_

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
  public:
    FragTrap();
    FragTrap(std::string name);
    FragTrap(std::string name, int hitpoint, int energy_point, int attack_dmg);
    FragTrap(FragTrap &obj);
    FragTrap &operator=(FragTrap &rhs);
    virtual ~FragTrap();

    void highFivesGuys(void);
};

#endif