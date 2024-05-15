/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:50:49 by rcutte            #+#    #+#             */
/*   Updated: 2024/05/06 18:25:24 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

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

void  testBureaucrat(){
  SeparatorMsg("Bureaucrat");
  {
    Bureaucrat basic;
    std::cout << basic;
  }
  SeparatorLine();
  {
    Bureaucrat *test = new Bureaucrat();
    std::cout << *test;
    try {
      test->upGrade(5);
      std::cout << *test;
      test->downGrade(10);
    }
    catch (std::exception & e){
      std::cout
        << REDB << "ERROR" << RESET << " " 
        << BRED << e.what() << RESET << "\n";
    }
    std::cout << *test;
    delete test;
  }
  SeparatorLine();
  {
    Bureaucrat a = Bureaucrat("BoringGuy", 10);
    Bureaucrat b = a;
    std::cout << a;
    std::cout << b;
  }
}

int main(){
  testBureaucrat();
}