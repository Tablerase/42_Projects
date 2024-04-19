/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 23:20:29 by rcutte            #+#    #+#             */
/*   Updated: 2024/04/16 22:28:21 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H_
# define FRAGTRAP_H_

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
  protected:
    int hit_point_;
    int attack_dmg_;

  public:
    FragTrap();
    FragTrap(std::string name);
    FragTrap(std::string name, int hitpoint, int energy_point, int attack_dmg);
    FragTrap(FragTrap &obj);
    FragTrap &operator=(FragTrap &rhs);
    virtual ~FragTrap();

    virtual int getHitPoint();
    virtual int getAttackDmg();
    virtual void setHitPoint(int amount);
    virtual void setAttackDmg(int amount);

    void highFivesGuys(void);
};

#endif