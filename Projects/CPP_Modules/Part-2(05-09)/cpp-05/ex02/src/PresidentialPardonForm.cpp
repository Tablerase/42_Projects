/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 01:40:42 by rcutte            #+#    #+#             */
/*   Updated: 2024/05/14 21:56:41 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PresidentialPardonForm.hpp"

/* ======================== Constructor / Destructor ======================== */

PresidentialPardonForm::PresidentialPardonForm() :
  AForm("President Default Pardon Form", 25, 5),
  target_("José Bové")
{
  #ifdef LOG
  std::cout
    << MAGB << "🤲 Constructor PresidentialPardonForm by default"
    << RESET << "\n";
  #endif
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) :
  AForm("President Pardon Form", 25, 5),
  target_(target)
{
  #ifdef LOG
  std::cout
    << MAGB << "🤲 Constructor PresidentialPardonForm by param"
    << RESET << "\n";
  #endif
}

PresidentialPardonForm::~PresidentialPardonForm()
{
  #ifdef LOG
  std::cout
    << BLKB << "🤲 Destructor PresidentialPardonForm by default"
    << RESET << "\n";
  #endif
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
  : AForm(other)
{
  if (this != &other) {
    this->target_ = other.target_;
  }
  #ifdef LOG
  std::cout
    << MAGB << "🤲 Constructor PresidentialPardonForm by copy"
    << RESET << "\n";
  #endif
}

PresidentialPardonForm &PresidentialPardonForm::operator=(
  const PresidentialPardonForm &other)
{
  if (this != &other){
    AForm::operator=(other);
    this->target_ = other.target_;
  }
  #ifdef LOG
  std::cout
    << MAGB << "🤲 Constructor PresidentialPardonForm by assign"
    << RESET << "\n";
  #endif
  return *this;
}

/* ================================= Getter ================================= */

const std::string &PresidentialPardonForm::get_target() const {
  return this->target_;
}

/* ================================= Setter ================================= */

void PresidentialPardonForm::set_target(const std::string target){
  if (target.empty() == false)
    this->target_ = target;
}

/* =============================== Functions ================================ */

/**
 * @brief Execute the President Pardon Form
 * @param executor Bureaucrate that will execute the President pardon form
 * @note If bureaucrate grade is greater than form exec grade, a president
 * pardon will be tryed.
 * @exception recover from checkExecuteConditions
*/
void  PresidentialPardonForm::execute(Bureaucrat const & executor) const {
  this->checkExecuteConditions(executor);
  std::cout
    << "🤲 "
    << BMAG << this->get_target()
    << RESET << " has been pardoned by Zaphod Beeblebrox !\n";
}
