/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:57:44 by rcutte            #+#    #+#             */
/*   Updated: 2024/05/14 01:10:18 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

/* ======================== Constructor / Destructor ======================== */

Bureaucrat::Bureaucrat() : name_("BuBuDefault"), grade_(150)
{
  #ifdef LOG
  std::cout << BLUB << "💼 Constructor Bureaucrat by default" << RESET << "\n";
  #endif
}

Bureaucrat::~Bureaucrat()
{
  #ifdef LOG
  std::cout << BLKB << "💼‍ Destructor Bureaucrat by default" << RESET << "\n";
  #endif
}

Bureaucrat::Bureaucrat(const std::string name, const int grade)
  : name_(name)
{
  #ifdef LOG
  std::cout << BLUB << "💼 Constructor Bureaucrat by param" << RESET << "\n";
  #endif
  this->setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
  : name_(other.name_ + " [copy]")
{
  *this = other;
  #ifdef LOG
  std::cout << BLUB << "💼 Constructor Bureaucrat by copy" << RESET << "\n";
  #endif
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
  if (this != &other){
    this->setGrade(other.grade_);
  }
  #ifdef LOG
  std::cout << BLUB << "💼 Constructor Bureaucrat by assign" << RESET << "\n";
  #endif
  return *this;
}

/* ================================= Getter ================================= */

std::string const &Bureaucrat::get_name() const {
  return this->name_;
}

int Bureaucrat::getGrade() const {
  return this->grade_;
}

/* ================================= Setter ================================= */

/**
 * @brief Set grade between 1 (best) and 150 (worst) include
 * @param grade new grade to assign
*/
void  Bureaucrat::setGrade(const int grade){
  if (grade >= 1 && grade <= 150)
    this->grade_ = grade;
  else if (grade < 1)
    throw Bureaucrat::GradeTooHighException();
  else
    throw Bureaucrat::GradeTooLowException();
}

/**
 * @brief Make the grade of the bureaucrat increase from 150 to 1
 * @param amount Rank increase amount
*/
void  Bureaucrat::upGrade(const int amount){
  if (this->grade_ - amount < 1 || amount > 150)
    throw Bureaucrat::GradeTooHighException();
  else
    this->grade_ -= amount;
}

/**
 * @brief Make the grade of the bureaucrat decrease from 1 to 150
 * @param amount Rank decrease amount
*/
void  Bureaucrat::downGrade(const int amount){
  if (this->grade_ + amount > 150 || amount > 150)
    throw Bureaucrat::GradeTooLowException();
  else
    this->grade_ += amount;
}

/* =============================== Functions ================================ */

void Bureaucrat::signForm(AForm &document){
  try {
    document.beSigned(*this);
    std::cout
      << "💼 "
      << BYEL << this->get_name()
      << RESET << " signed "
      << BBLU << document.get_name() << RESET << "\n";
  }
  catch (std::exception &e) {
    std::cerr
      << REDB << "ERROR" << RESET << " " << BYEL
      << this->get_name() << RESET << " couldn’t sign "
      << BYEL << document.get_name()
      << RESET << " because "
      << BRED << e.what() << RESET << "\n";
  }
}

/**
 * @brief Execution of a form
 * @note The bureaucrat try to execute the form if succeed print a msg
 * else catch and write an appropriate error msg
*/
void  Bureaucrat::executeForm(AForm const & form){
  try {
    form.execute(*this);
    std::cout
      << "💼 "
      << BYEL << this->get_name() << RESET
      << " executed " << BBLU << form.get_name() << RESET << "\n";
  }
  catch (std::exception &e){
    std::cerr
      << REDB << "ERROR" << RESET << " "
      << BRED << e.what() << RESET << "\n";
  }
}

/* =============================== Exceptions =============================== */

const char* Bureaucrat::GradeTooHighException::what() const throw(){
  return "Bureaucrat Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
  return "Bureaucrat Grade is too low!";
}

/* ================================= Output ================================= */

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj){
  os
    << YELB << "💼 BUREAUCRAT" << RESET << " "
    << BYEL << obj.get_name() << RESET
    << " has a grade of " << BBLU << obj.getGrade() << RESET << "\n";
  return os;
}