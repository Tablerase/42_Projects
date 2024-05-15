/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:31:24 by rcutte            #+#    #+#             */
/*   Updated: 2024/05/15 14:45:11 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Intern.hpp"

/* ======================== Constructor / Destructor ======================== */

Intern::Intern()
{
  #ifdef LOG
  std::cout << BLUB << "🎒 Constructor Intern by default" << RESET << "\n";
  #endif
}

Intern::~Intern()
{
  #ifdef LOG
  std::cout << BLKB << "🎒‍ Destructor Intern by default" << RESET << "\n";
  #endif
}

Intern::Intern(const Intern &other)
{
  *this = other;
  #ifdef LOG
  std::cout << BLUB << "🎒 Constructor Intern by copy" << RESET << "\n";
  #endif
}

Intern &Intern::operator=(const Intern &other)
{
  if (this != &other){}
  #ifdef LOG
  std::cout << BLUB << "🎒 Constructor Intern by assign" << RESET << "\n";
  #endif
  return *this;
}

/* =============================== Functions ================================ */

static AForm* createShrubberyCreationForm(const std::string& target) {
  return new ShrubberyCreationForm(target);
}

static AForm* createRobotomyRequestForm(const std::string& target) {
  return new RobotomyRequestForm(target);
}

static AForm* createPresidentialPardonForm(const std::string& target) {
  return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string form_name, const std::string target) {
  const int array_length = 3;
  const std::string array_forms[] = {
    "shrubbery creation",
    "robotomy request",
    "presidential pardon"
  };

  // Return type (array of ptr to functions)(function arguments) ...
  AForm* (*array_functions[])(const std::string &target) = {
    createShrubberyCreationForm,
    createRobotomyRequestForm,
    createPresidentialPardonForm
  };

  for (int i = 0; i < array_length; i++) {
    if (array_forms[i] == form_name) {
      return array_functions[i](target);
    }
  }
  throw AForm::InvalidFormName();
  return NULL;
}
