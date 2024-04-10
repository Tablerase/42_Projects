/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:27:09 by rcutte            #+#    #+#             */
/*   Updated: 2024/04/08 15:21:36 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

int main(){
  std::cout << WHTB << "Creating Zombies" << RESET << "\n";
  Zombie test("Kevin"); // Named zombie
  Zombie standard_zombie; // Default construct
  Zombie *zombie_alloc = newZombie("ZombAlloc"); // Alloc zombie
  randomChump("RandieZomb"); // Random Zombie (in a function)

  std::cout << WHTB << "Speaking with Zombies" << RESET << "\n";
  test.annonce();
  zombie_alloc->annonce();
  standard_zombie.annonce();

  std::cout << WHTB << "Slaying Zombies" << RESET << "\n";
  delete zombie_alloc;
}
