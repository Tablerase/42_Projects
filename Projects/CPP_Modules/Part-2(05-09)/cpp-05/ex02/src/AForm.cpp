/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:52:24 by rcutte            #+#    #+#             */
/*   Updated: 2024/05/13 13:29:01 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"

/* ======================== Constructor / Destructor ======================== */

AForm::AForm()
  : name_("AFormDefault"),
    sign_grade_(150),
    exec_grade_(150),
    signed_(false)
{
  #ifdef LOG
  std::cout << BLUB << "📝 Constructor AForm by default" << RESET << "\n";
  #endif
}

AForm::~AForm()
{
  #ifdef LOG
  std::cout << BLKB << "📝 Destructor AForm by default" << RESET << "\n";
  #endif
}

AForm::AForm(const std::string name, const int sign_grade, const int exec_grade)
  : name_(name),
    sign_grade_(checkGrade(sign_grade)),
    exec_grade_(checkGrade(exec_grade)),
    signed_(false)
{
  #ifdef LOG
  std::cout << BLUB << "📝 Constructor AForm by param" << RESET << "\n";
  #endif
}

AForm::AForm(const AForm &other)
  : name_(other.name_ + " [copy]"),
    sign_grade_(checkGrade(other.sign_grade_)),
    exec_grade_(checkGrade(other.exec_grade_))
{
  *this = other;
  #ifdef LOG
  std::cout << BLUB << "📝 Constructor AForm by copy" << RESET << "\n";
  #endif
}

AForm &AForm::operator=(const AForm &other)
{
  if (this != &other){
    this->signed_ = other.signed_;
  }
  #ifdef LOG
  std::cout << BLUB << "📝 Constructor AForm by assign" << RESET << "\n";
  #endif
  return *this;
}

/* ================================= Getter ================================= */

const std::string &AForm::get_name() const {
  return this->name_;
}

const int &AForm::get_sign_grade() const {
  return this->sign_grade_;
}

const int &AForm::get_exec_grade() const {
  return this->exec_grade_;
}

const bool &AForm::get_signed_status() const {
  return this->signed_;
}

/* ================================= Setter ================================= */

/**
 * @brief Check grade value if between 1 (best) and 150 (worst) include
 * @param grade grade to check
 * @return grade or error
*/
int  AForm::checkGrade(const int grade) const {
  if (grade < 1)
    throw AForm::GradeTooHighException();
  else if (grade > 150)
    throw AForm::GradeTooLowException();
  else
    return grade;
}

/* =============================== Functions ================================ */

/**
 * @brief Sign the form
 * @note If the bureaucrat is qualified it can change status sign to true
*/
void  AForm::beSigned(Bureaucrat &agent){
  if (this->signed_ == false){
    if (agent.getGrade() <= this->get_sign_grade()){
      this->signed_ = true;
    }
    else {
      // throw AForm::GradeTooLowException(); Bureaucrat grade is too low not the Aform grade
      throw AForm::GradeTooHighException();
    }
  }
}

/**
 * @brief Check if executor can use the form
 * @note Success if executor grade greater or equal to form exec grade and
 * if the form is signed
 * @exception throw form signature error or form grade error
*/
void AForm::checkExecuteConditions(Bureaucrat const & executor) const {
  if (this->get_signed_status() == false) {
      throw AForm::SignatureNecessary();
  }
  if (this->get_exec_grade() < executor.getGrade()) {
      throw AForm::GradeTooHighException();
  }
}

/* =============================== Exceptions =============================== */

const char* AForm::GradeTooHighException::what() const throw(){
  return "Form Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw(){
  return "Form Grade is too low!";
}

const char* AForm::SignatureNecessary::what() const throw(){
  return "Form signature is needed";
}

/* ================================= Output ================================= */

std::ostream &operator<<(std::ostream &os, const AForm &obj){
  os
    << YELB << "📝 FORM" << RESET << " "
    << BYEL << obj.get_name() << RESET
    << (obj.get_signed_status() == false ? " is not signed" : " is signed")
    << ", has " << BBLU << obj.get_sign_grade() << RESET << " sign grade"
    << ", " << BBLU << obj.get_exec_grade() << RESET << " exec grade\n";
  return os;
}