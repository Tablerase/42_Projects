/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:27:09 by rcutte            #+#    #+#             */
/*   Updated: 2024/04/08 15:45:55 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

int main(){
  std::cout << WHTB << "Creating Zombies" << RESET << "\n";
  int horde_size = 10;
  Zombie *horde = zombieHorde(horde_size, "ZombOrder");

  std::cout << WHTB << "Speaking with Zombies" << RESET << "\n";
  horde->annonce(); // Check is Name of first element
  for (int i= 0; i < horde_size; i++)
  {
    horde[i].annonce();
  }

  std::cout << WHTB << "Slaying Zombies" << RESET << "\n";
  delete[] horde;
}
