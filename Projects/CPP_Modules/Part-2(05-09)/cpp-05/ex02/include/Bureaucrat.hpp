/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:54:01 by rcutte            #+#    #+#             */
/*   Updated: 2024/05/13 23:15:16 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H_
#define BUREAUCRAT_H_

# include <iostream>
# include <iomanip>
# include <stdexcept>
# include "color.h"
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
private:
  const std::string name_;
  int               grade_;

public:
  Bureaucrat();
  Bureaucrat(const std::string name, const int grade);
  Bureaucrat(const Bureaucrat &other);
  Bureaucrat &operator=(const Bureaucrat &other);
  ~Bureaucrat();

  std::string const &get_name() const;
  int getGrade() const;

  void  setGrade(const int amount);
  void  upGrade(const int amount);
  void  downGrade(const int amount);

  void  signForm(AForm &document);
  void  executeForm(AForm const & form);
  
  class GradeTooHighException : public std::exception {
    public:
      const char* what() const throw();
  };
  class GradeTooLowException : public std::exception {
    public:
      const char* what() const throw();
  };
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj);

#endif