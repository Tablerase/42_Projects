/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:44:32 by rcutte            #+#    #+#             */
/*   Updated: 2024/04/22 17:05:18 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Character.hpp"
#include "../include/IMateriaSource.hpp"
#include "../include/MateriaSource.hpp"
#include "../include/Ice.hpp"
#include "../include/Cure.hpp"

#define SEPARATOR_LENGHT 60

void SeparatorLine(){
  #ifdef LOG
  std::cout
    << BLU
    << std::setw(SEPARATOR_LENGHT) << std::setfill('-')
    << RESET << "\n";
  #endif
}

void SeparatorMsg(std::string msg){
  int msg_len = msg.length();
  int inter_space = (SEPARATOR_LENGHT - msg_len) / 2;
  std::cout
    << std::setw(SEPARATOR_LENGHT) << std::setfill('=') << "\n"
    << "|" << std::setw(inter_space + 1) << std::setfill(' ') << RESET
    << msg ;
  if (msg_len % 2 == 1)
    std::cout << " ";
  std::cout
    << std::setw(inter_space + 1) << "|" << "\n"
    << std::setw(SEPARATOR_LENGHT) << std::setfill('=') << "\n";
}

void TestMateriaSource(){
  #ifdef LOG
  SeparatorMsg("MateriaSource");
  MateriaSource *src = new MateriaSource();
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());
  src->learnMateria(new Ice());
  src->learnMateria(new Ice());
  src->learnMateria(new Ice()); // Out of space should be freed
  SeparatorLine();
  IMateriaSource  *copy_src = new MateriaSource(*src);
  SeparatorLine();
  delete src;
  SeparatorLine();
  delete copy_src;
  #endif
}

void TestCharacter(){
  #ifdef LOG
  SeparatorMsg("Character");
  Character sephiroth = Character("Sephiroth");
  sephiroth.equip(new Cure());
  sephiroth.equip(new Cure());
  sephiroth.equip(new Cure());
  sephiroth.equip(new Cure());
  // Copy Char
  Character good_sephirot = Character("Good Sephirot");
  good_sephirot = sephiroth;
  std::cout << MAGB << good_sephirot.getName() << RESET << " ";
  good_sephirot.use(0, sephiroth);
  Character test = good_sephirot;
  #endif
}

void Test(){
  // Creating the source
  SeparatorMsg("TEST");
  IMateriaSource* src = new MateriaSource();
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());
  // Creating character
  SeparatorLine();
  ICharacter* cloud = new Character();
  std::cout << "Hello my name is " << BBLU << cloud->getName() << RESET << "\n";
  // Learning Spell
  SeparatorLine();
  cloud->equip(src->createMateria("ice"));
  cloud->equip(new Cure());
  // Creating Targets
  SeparatorLine();
  Character sephiroth = Character("Sephiroth");
  std::cout << "Hello my name is " << BYEL << sephiroth.getName() << RESET << "\n";
  sephiroth.equip(src->createMateria("ice"));
  sephiroth.equip(src->createMateria("ice"));
  sephiroth.equip(src->createMateria("ice"));
  sephiroth.equip(src->createMateria("ice"));
  sephiroth.equip(src->createMateria("ice")); // Out of space should be freed
  ICharacter *tifa = new Character("Tipha");
  std::cout << "Hello my name is " << BBLU << tifa->getName() << RESET << "\n";
  // Use materia on Target
  SeparatorLine();
  std::cout << MAGB << cloud->getName() << RESET << " ";
  cloud->use(0, sephiroth);
  std::cout << MAGB << sephiroth.getName() << RESET << " ";
  sephiroth.use(0, *cloud);
  std::cout << MAGB << sephiroth.getName() << RESET << " ";
  sephiroth.use(1, *tifa);
  std::cout << MAGB << sephiroth.getName() << RESET << " ";
  sephiroth.use(2, *tifa);
  std::cout << MAGB << sephiroth.getName() << RESET << " ";
  sephiroth.use(3, *tifa);
  std::cout << MAGB << sephiroth.getName() << RESET << " ";
  sephiroth.use(4, *tifa); // Shouldnt be usable (out of slot range)
  std::cout << MAGB << cloud->getName() << RESET << " ";
  cloud->use(1, *tifa);
  // Unequip
  std::cout << MAGB << cloud->getName() << RESET << " ";
  cloud->unequip(0);
  std::cout << MAGB << cloud->getName() << RESET << " ";
  cloud->use(0, *tifa);
  // Free memory
  SeparatorLine();
  delete cloud;
  delete src;
  delete tifa;
}

int main(){
  TestMateriaSource();
  TestCharacter();
  Test();
}

// Test by default
// int main()
// {
//   IMateriaSource* src = new MateriaSource();
//   src->learnMateria(new Ice());
//   src->learnMateria(new Cure());
//   ICharacter* me = new Character("me");
//   AMateria* tmp;
//   tmp = src->createMateria("ice");
//   me->equip(tmp);
//   tmp = src->createMateria("cure");
//   me->equip(tmp);
//   ICharacter* bob = new Character("bob");
//   me->use(0, *bob);
//   me->use(1, *bob);
//   delete bob;
//   delete me;
//   delete src;
//   return 0;
// }
