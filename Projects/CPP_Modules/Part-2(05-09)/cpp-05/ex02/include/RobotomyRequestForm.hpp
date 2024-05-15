/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 00:22:26 by rcutte            #+#    #+#             */
/*   Updated: 2024/05/14 00:43:34 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_H_
#define ROBOTOMYREQUESTFORM_H_

# include <cstdlib> // for std::rand and std::srand
# include <ctime> // for std::time
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
  std::string target_;

public:
  RobotomyRequestForm();
  RobotomyRequestForm(const std::string target);
  RobotomyRequestForm(const RobotomyRequestForm &other);
  RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
  ~RobotomyRequestForm();

  const std::string &get_target() const;
  void set_target(const std::string target);
  
  void execute(Bureaucrat const & executor) const;
};

#endif