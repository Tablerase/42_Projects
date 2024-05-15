/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:51:38 by rcutte            #+#    #+#             */
/*   Updated: 2024/05/13 17:51:03 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H_
#define FORM_H_

# include <iostream>
# include <iomanip>
# include <stdexcept>
# include "../include/color.h"
# include "../include/Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
  const std::string name_;
  const int         sign_grade_;
  const int         exec_grade_;
  bool              signed_;

public:
  Form();
  Form(const std::string name, const int signed_grade, const int exec_grade);
  Form(const Form &other);
  Form &operator=(const Form &other);
  ~Form();

  std::string const &get_name() const;
  const int &get_sign_grade() const;
  const int &get_exec_grade() const;
  const bool &get_signed_status() const;

  int  checkGrade(const int grade) const;
  void  beSigned(Bureaucrat &agent);
  
  class GradeTooHighException : public std::exception {
    public:
      const char* what() const throw();
  };
  class GradeTooLowException : public std::exception {
    public:
      const char* what() const throw();
  };
};

std::ostream &operator<<(std::ostream &os, const Form &obj);

#endif