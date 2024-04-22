/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 13:15:22 by rcutte            #+#    #+#             */
/*   Updated: 2024/04/17 14:12:23 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"
#include "../include/Dog.hpp"
#include "../include/Cat.hpp"
#include "../include/WrongAnimal.hpp"
#include "../include/WrongCat.hpp"

void SeparatorMsg(std::string msg){
  int separator_lenght = 60;
  int msg_len = msg.length();
  int inter_space = (separator_lenght - msg_len) / 2;
  std::cout
    << std::setw(separator_lenght) << std::setfill('=') << "\n"
    << "|" << std::setw(inter_space + 1) << std::setfill(' ') << RESET
    << msg ;
  if (msg_len % 2 == 1)
    std::cout << " ";
  std::cout
    << std::setw(inter_space + 1) << "|" << "\n"
    << std::setw(separator_lenght) << std::setfill('=') << "\n";
}

void TestAnimal(){
  Animal a;
  std::cout << a;
  Animal b("Bear");
  std::cout << b;
  std::cout << "--------- Pointer Animal --------- \n";
  Animal *ptr = new Animal("Animal Pointer");
  std::cout << *ptr;
  ptr->makeSound();
  delete ptr;
}

void TestDog(){
  Dog b;
  std::cout << b;
  b.makeSound();
  std::cout << "--------- Pointer Animal --------- \n";
  Animal *ptr = new Dog();
  std::cout << *ptr;
  ptr->makeSound();
  delete ptr; // only one object to del animal
}

void TestCat(){
  Cat b;
  std::cout << b;
  b.makeSound();
  std::cout << "--------- Pointer Animal --------- \n";
  Animal *ptr = new Cat();
  std::cout << *ptr;
  ptr->makeSound();
  delete ptr; // only one object to del animal
}

void TestWrong(){
  WrongCat b;
  std::cout << b;
  b.makeSound();
  std::cout << "--------- Pointer WrongAnimal --------- \n";
  WrongAnimal *ptr = new WrongCat();
  std::cout << *ptr;
  std::cout << RED << "Wrong song because virtual not apply (Default instead of Cat)" << RESET << "\n";
  ptr->makeSound();
  std::cout
    << RED << "One delete (Wrong Cat) not done because virtual not apply on destructor"
    << RESET << "\n";
  delete ptr;
}

int main()
{
  SeparatorMsg("Animal");
  TestAnimal();
  SeparatorMsg("Dog");
  TestDog();
  SeparatorMsg("Cat");
  TestCat();
  SeparatorMsg("Wrong Doing");
  TestWrong();
}

// Default test
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