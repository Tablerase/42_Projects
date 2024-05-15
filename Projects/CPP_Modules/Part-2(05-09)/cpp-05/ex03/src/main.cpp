/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:50:49 by rcutte            #+#    #+#             */
/*   Updated: 2024/05/15 14:46:32 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/Intern.hpp"

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

void testIntern(){
  SeparatorMsg("Intern");
  // check error
  {
    try {
      Intern noob;
      AForm *test = noob.makeForm("test", "test");
      delete test;
    }
    catch (std::exception &e){
      std::cout << BRED << e.what() << RESET << "\n";
    }
  }
  SeparatorLine();
  // check usage
  {
    Intern      noob;
    Bureaucrat  agent("Senior Agent", 1);
    try {
      AForm *recover = noob.makeForm("robotomy request", "astro boy");
      agent.signForm(*recover);
      agent.executeForm(*recover);
      delete recover;
    }
    catch (std::exception &e){
      std::cout << BRED << e.what() << RESET << "\n";
    }
  }
}

int main(){
  // Tests
  testIntern();
}
