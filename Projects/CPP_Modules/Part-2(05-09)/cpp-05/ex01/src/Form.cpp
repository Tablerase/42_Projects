/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:52:24 by rcutte            #+#    #+#             */
/*   Updated: 2024/05/13 17:51:03 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.hpp"

/* ======================== Constructor / Destructor ======================== */

Form::Form()
  : name_("FormDefault"),
    sign_grade_(150),
    exec_grade_(150),
    signed_(false)
{
  #ifdef LOG
  std::cout << BLUB << "📝 Constructor Form by default" << RESET << "\n";
  #endif
}

Form::~Form()
{
  #ifdef LOG
  std::cout << BLKB << "📝 Destructor Form by default" << RESET << "\n";
  #endif
}

Form::Form(const std::string name, const int sign_grade, const int exec_grade)
  : name_(name),
    sign_grade_(checkGrade(sign_grade)),
    exec_grade_(checkGrade(exec_grade)),
    signed_(false)
{
  #ifdef LOG
  std::cout << BLUB << "📝 Constructor Form by param" << RESET << "\n";
  #endif
}

Form::Form(const Form &other)
  : name_(other.name_ + " [copy]"),
    sign_grade_(checkGrade(other.sign_grade_)),
    exec_grade_(checkGrade(other.exec_grade_))
{
  *this = other;
  #ifdef LOG
  std::cout << BLUB << "📝 Constructor Form by copy" << RESET << "\n";
  #endif
}

Form &Form::operator=(const Form &other)
{
  if (this != &other){
    this->signed_ = other.signed_;
  }
  #ifdef LOG
  std::cout << BLUB << "📝 Constructor Form by assign" << RESET << "\n";
  #endif
  return *this;
}

/* ================================= Getter ================================= */

const std::string &Form::get_name() const {
  return this->name_;
}

const int &Form::get_sign_grade() const {
  return this->sign_grade_;
}

const int &Form::get_exec_grade() const {
  return this->exec_grade_;
}

const bool &Form::get_signed_status() const {
  return this->signed_;
}

/* ================================= Setter ================================= */

/**
 * @brief Check grade value if between 1 (best) and 150 (worst) include
 * @param grade grade to check
 * @return grade or error
*/
int  Form::checkGrade(const int grade) const {
  if (grade < 1)
    throw Form::GradeTooHighException();
  else if (grade > 150)
    throw Form::GradeTooLowException();
  else
    return grade;
}

/* =============================== Functions ================================ */

/**
 * @brief Sign the form
 * @note If the bureaucrat is qualified it can change status sign to true
*/
void  Form::beSigned(Bureaucrat &agent){
  if (this->signed_ == false){
    if (agent.getGrade() <= this->get_sign_grade()){
      this->signed_ = true;
    }
    else {
      // throw Form::GradeTooLowException(); Bureaucrat grade is too low not the form grade
      throw Form::GradeTooHighException();
    }
  }
}

/* =============================== Exceptions =============================== */

const char* Form::GradeTooHighException::what() const throw(){
  return "Form Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw(){
  return "Form Grade is too low!";
}

/* ================================= Output ================================= */

std::ostream &operator<<(std::ostream &os, const Form &obj){
  os
    << YELB << "📝 FORM" << RESET << " "
    << BYEL << obj.get_name() << RESET
    << (obj.get_signed_status() == false ? " is not signed" : " is signed")
    << ", has " << BBLU << obj.get_sign_grade() << RESET << " sign grade"
    << ", " << BBLU << obj.get_exec_grade() << RESET << " exec grade\n";
  return os;
}