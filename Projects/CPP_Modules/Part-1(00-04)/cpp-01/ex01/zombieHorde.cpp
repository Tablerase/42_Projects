/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:27:52 by rcutte            #+#    #+#             */
/*   Updated: 2024/04/08 15:47:58 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/**
 * @brief Create a horde according to Size
 * @note Add a num to zombie name to know it's birth order in the horde array
*/
Zombie* zombieHorde( int N, std::string name ){
  Zombie *horde = new Zombie[N];
  for(int i= 0; i < N; i++)
  {
    horde[i].setName(name + "[" + std::to_string(i) + "]");
  }
  return horde;
}
