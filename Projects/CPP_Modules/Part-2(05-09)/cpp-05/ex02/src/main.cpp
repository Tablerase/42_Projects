/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:50:49 by rcutte            #+#    #+#             */
/*   Updated: 2024/05/14 12:20:24 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

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

void  testAForm(){
  // Abstract test use make abstract rule
  #ifdef ABSTRACT
  SeparatorMsg("AForm");
  {
    AForm paper;
    std::cout << paper;
  }
  #endif
}

void testShrubbery(){
  // Simple Instance
  SeparatorMsg("Shrubbery | sign 145, exec 137");
  {
    ShrubberyCreationForm test;
    std::cout << test;
  }
  // Abstract ptr + Catch error
  SeparatorLine();
  {
    Bureaucrat agent("Middle Agent", 75);
    ShrubberyCreationForm test("Garden");
    std::cout << test;
    try {
      test.execute(agent);
    }
    catch (std::exception &e){
      std::cout
        << REDB << "ERROR" << RESET << " "
        << BRED << e.what() << RESET << "\n";
    }
    AForm *ptr_test = new ShrubberyCreationForm(test);
    std::cout << *ptr_test;
    try {
      ptr_test->execute(agent);
    }
    catch (std::exception &e){
      std::cout
        << REDB << "ERROR" << RESET << " "
        << BRED << e.what() << RESET << "\n";
    }
    delete ptr_test;
  }
  // Execute from Form and From Bureaucrat
  SeparatorLine();
  {
    Bureaucrat agent("Middle Agent", 75);
    Bureaucrat agent_150("Noob Agent", 150);
    ShrubberyCreationForm test("Garden");
    test.beSigned(agent);
    std::cout << test;
    try {
      test.execute(agent);
      test.execute(agent_150); // form too high
    }
    catch (std::exception &e) {
      std::cout
        << REDB << "ERROR" << RESET << " "
        << BRED << e.what() << RESET << "\n";
    }
    ShrubberyCreationForm test_bu_form("Patio");
    agent.signForm(test_bu_form);
    agent.executeForm(test_bu_form);
  }
}

void  testRobotomy(){
  SeparatorMsg("Robotomy | sign 72, exec 45");
  {
    Bureaucrat agent("Good Agent", 35);
    Bureaucrat agent_bad("Not Good Enougth Agent", 75);
    RobotomyRequestForm form("Astro Boy");
    std::cout << form;
    agent.signForm(form);
    agent.executeForm(form);
    agent_bad.executeForm(form);
  }
}

void testPardon(){
  SeparatorMsg("Pardon | sign 25, exec 5");
  {
    Bureaucrat agent("Master Agent", 5);
    Bureaucrat agent_bad("Not Good Enougth Agent", 75);
    PresidentialPardonForm form("Bastard");
    std::cout << form;
    agent.signForm(form);
    agent.executeForm(form);
    agent_bad.executeForm(form);
  }
}

int main(){
  // Initialize random seed
  std::srand(std::time(0));
  // Tests
  SeparatorMsg("Highest: 1 | Lowest: 150");
  testAForm();
  testShrubbery();
  testRobotomy();
  testPardon();
}
