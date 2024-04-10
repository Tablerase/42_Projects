/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:29:43 by rcutte            #+#    #+#             */
/*   Updated: 2024/04/08 14:57:27 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ZOMBIE_H__
#define ZOMBIE_H__

#include <iostream>
#include <string>

#include "color.h"

class Zombie
{
private:
  std::string name_;
public:
  Zombie();
  Zombie(std::string name);
  ~Zombie();
  
  void annonce();
};

Zombie* newZombie( std::string name );

void randomChump( std::string name );

#endif