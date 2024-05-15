/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:27:52 by rcutte            #+#    #+#             */
/*   Updated: 2024/05/15 19:05:59 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <sstream>

/**
 * @brief Create a horde according to Size
 * @note Add a num to zombie name to know it's birth order in the horde array
*/
Zombie* zombieHorde( int N, std::string name ){
  Zombie *horde = new Zombie[N];
  for(int i= 0; i < N; i++)
  {
    std::stringstream ss;
    ss << i;
    horde[i].setName(name + "[" + ss.str() + "]");
  }
  return horde;
}
