/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:51:38 by rcutte            #+#    #+#             */
/*   Updated: 2024/05/13 13:55:53 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_H_
#define AFORM_H_

# include <iostream>
# include <fstream>
# include <iomanip>
# include <stdexcept>
# include "color.h"
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
  const std::string name_;
  const int         sign_grade_;
  const int         exec_grade_;
  bool              signed_;

public:
  AForm();
  AForm(const std::string name, const int signed_grade, const int exec_grade);
  AForm(const AForm &other);
  AForm &operator=(const AForm &other);
  virtual ~AForm();

  virtual void execute(Bureaucrat const & executor) const = 0;

  std::string const &get_name() const;
  const int         &get_sign_grade() const;
  const int         &get_exec_grade() const;
  const bool        &get_signed_status() const;

  int   checkGrade(const int grade) const;
  void  beSigned(Bureaucrat &agent);
  
  void  checkExecuteConditions(Bureaucrat const & executor) const;
  class GradeTooHighException : public std::exception {
    public:
      const char* what() const throw();
  };
  class GradeTooLowException : public std::exception {
    public:
      const char* what() const throw();
  };
  class SignatureNecessary : public std::exception {
    public:
      const char* what() const throw();
  };
  class InvalidFormName : public std::exception {
    public:
      const char* what() const throw();
  };
};

std::ostream &operator<<(std::ostream &os, const AForm &obj);

#endif