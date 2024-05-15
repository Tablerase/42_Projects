/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 00:28:16 by rcutte            #+#    #+#             */
/*   Updated: 2024/05/14 19:06:07 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RobotomyRequestForm.hpp"

/* ======================== Constructor / Destructor ======================== */

RobotomyRequestForm::RobotomyRequestForm() :
  AForm("RobotomyDefaultForm", 72, 45),
  target_("Rei Ayanami") // Evangelion U00
{
  #ifdef LOG
  std::cout
    << GRAYB << "🤖 Constructor RobotomyRequestForm by default"
    << RESET << "\n";
  #endif
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) :
  AForm("Robotomy Form", 72, 45),
  target_(target)
{
  #ifdef LOG
  std::cout
    << GRAYB << "🤖 Constructor RobotomyRequestForm by param"
    << RESET << "\n";
  #endif
}

RobotomyRequestForm::~RobotomyRequestForm()
{
  #ifdef LOG
  std::cout
    << BLKB << "🤖 Destructor RobotomyRequestForm by default"
    << RESET << "\n";
  #endif
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
  : AForm(other)
{
  if (this != &other) {
    this->target_ = other.target_;
  }
  #ifdef LOG
  std::cout
    << GRAYB << "🤖 Constructor RobotomyRequestForm by copy"
    << RESET << "\n";
  #endif
}

RobotomyRequestForm &RobotomyRequestForm::operator=(
  const RobotomyRequestForm &other)
{
  if (this != &other){
    AForm::operator=(other);
    this->target_ = other.target_;
  }
  #ifdef LOG
  std::cout
    << GRAYB << "🤖 Constructor RobotomyRequestForm by assign"
    << RESET << "\n";
  #endif
  return *this;
}

/* ================================= Getter ================================= */

const std::string &RobotomyRequestForm::get_target() const {
  return this->target_;
}

/* ================================= Setter ================================= */

void RobotomyRequestForm::set_target(const std::string target){
  if (target.empty() == false)
    this->target_ = target;
}

/* =============================== Functions ================================ */

/**
 * @brief Execute the Robotomy
 * @param executor Bureaucrate that will execute the Robotomy Request form
 * @note If bureaucrate grade is greater than form exec grade, a robotomy will
 * be tryed and will have 50% of success.
 * @exception recover from checkExecuteConditions
*/
void  RobotomyRequestForm::execute(Bureaucrat const & executor) const {
  // Initialize random seed
  std::srand(std::time(0));
  this->checkExecuteConditions(executor);
  std::cout
    << GRAYB << "🤖 Bzzt bzzt Bzzt bzzt" << RESET << "\n";
  int random = std::rand() % 2;
  if (random == 0){
    std::cout
      << GRAYB << "🦾💪 " + this->get_target() + " 🦵🦿"
      << RESET << " has been robotomized !\n";
  } else {
    std::cout
      << "🤖 Robotomy " << BRED << "failed" << RESET << " !!\n";
  }
}
