/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:29:56 by rcutte            #+#    #+#             */
/*   Updated: 2024/05/13 18:03:30 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_H_
#define SHRUBBERYCREATIONFORM_H_

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
  std::string target_;

public:
  ShrubberyCreationForm();
  ShrubberyCreationForm(const std::string target);
  ShrubberyCreationForm(const ShrubberyCreationForm &other);
  ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
  ~ShrubberyCreationForm();

  const std::string &get_target() const;
  void set_target(const std::string target);
  
  void execute(Bureaucrat const & executor) const;
};

#endif