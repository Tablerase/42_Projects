/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:31:22 by rcutte            #+#    #+#             */
/*   Updated: 2024/05/14 13:57:24 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H_
#define INTERN_H_

# include "AForm.hpp"
# include "../include/ShrubberyCreationForm.hpp"
# include "../include/RobotomyRequestForm.hpp"
# include "../include/PresidentialPardonForm.hpp"

class Intern
{
public:
  Intern();
  Intern(const Intern &other);
  Intern &operator=(const Intern &other);
  ~Intern();

  AForm* makeForm(const std::string form_name, const std::string target);
};

#endif