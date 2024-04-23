/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 13:15:22 by rcutte            #+#    #+#             */
/*   Updated: 2024/04/18 00:38:08 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"
#include "../include/Dog.hpp"
#include "../include/Cat.hpp"
#include "../include/Brain.hpp"

#define SEPARATOR_LENGHT 60

void SeparatorLine(){
  std::cout
    << BLU
    << std::setw(SEPARATOR_LENGHT) << std::setfill('-')
    << RESET << "\n";
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

void TestBrain(){
  Brain a;
  SeparatorLine();
  Brain b(a);
  SeparatorLine();
}

void TestDog(){
  Dog a;
  SeparatorLine();
  Dog b(a);
  SeparatorLine();
  std::cout << "Animal pointer to dog instance" << "\n";
  Animal *doggy = new Dog();
  doggy->makeSound();
  delete doggy;
  SeparatorLine();
}

void TestCat(){
  Cat a;
  SeparatorLine();
  Cat b(a);
  SeparatorLine();
  std::cout << "Animal pointer to Cat instance" << "\n";
  Animal *Catgy = new Cat();
  Catgy->makeSound();
  delete Catgy;
  SeparatorLine();
}

void TestArray(){
  // Create List of Animals: half cat , half dog
  int array_size = 10;
  Animal **list = new Animal*[array_size];
  for (int i = 0; i < (array_size / 2); i++) {
    list[i] = new Cat();
  }
  for (int i = 5; i < (array_size); i++) {
    list[i] = new Dog();
  }
  SeparatorLine();
  // Print Sound
  for (int i = 0; i < array_size; i++) {
    list[i]->makeSound();
  }
  SeparatorLine();
  // Free Array
  for (int i = 0; i < array_size; i++) {
    delete list[i];
  }
  delete []list;
}

int main()
{
  SeparatorMsg("Brain");
  TestBrain();
  SeparatorMsg("Dog");
  TestDog();
  SeparatorMsg("Cat");
  TestCat();
  SeparatorMsg("Arrays");
  TestArray();
}

// // Default test
// int main()
// {
//   const Animal* meta = new Animal();
//   const Animal* j = new Dog();
//   const Animal* i = new Cat();
//   std::cout << j->getType() << " " << std::endl;
//   std::cout << i->getType() << " " << std::endl;
//   i->makeSound(); //will output the cat sound!
//   j->makeSound();
//   meta->makeSound();
//   delete j;
//   delete i;
//   delete meta;
// return 0;
// }