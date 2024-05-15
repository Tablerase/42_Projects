/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:35:46 by rcutte            #+#    #+#             */
/*   Updated: 2024/05/14 11:52:32 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_H_
#define PRESIDENTIALPARDONFORM_H_

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
  std::string target_;

public:
  PresidentialPardonForm();
  PresidentialPardonForm(const std::string target);
  PresidentialPardonForm(const PresidentialPardonForm &other);
  PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
  ~PresidentialPardonForm();

  const std::string &get_target() const;
  void set_target(const std::string target);
  
  void execute(Bureaucrat const & executor) const;
};

#endif