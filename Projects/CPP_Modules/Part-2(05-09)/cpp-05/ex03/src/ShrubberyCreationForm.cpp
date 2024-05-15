/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:30:02 by rcutte            #+#    #+#             */
/*   Updated: 2024/05/14 11:45:18 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ShrubberyCreationForm.hpp"

/* ======================== Constructor / Destructor ======================== */

ShrubberyCreationForm::ShrubberyCreationForm() :
  AForm("ShrubberDefaultForm", 145, 137),
  target_("Home")
{
  #ifdef LOG
  std::cout
    << GRNB << "🌳 Constructor ShrubberyCreationForm by default"
    << RESET << "\n";
  #endif
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) :
  AForm("Shrubber Form", 145, 137),
  target_(target)
{
  #ifdef LOG
  std::cout
    << GRNB << "🌳 Constructor ShrubberyCreationForm by param"
    << RESET << "\n";
  #endif
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
  #ifdef LOG
  std::cout
    << BLKB << "🌳 Destructor ShrubberyCreationForm by default"
    << RESET << "\n";
  #endif
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
  : AForm(other)
{
  if (this != &other) {
    this->target_ = other.target_;
  }
  #ifdef LOG
  std::cout
    << GRNB << "🌳 Constructor ShrubberyCreationForm by copy"
    << RESET << "\n";
  #endif
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(
  const ShrubberyCreationForm &other)
{
  if (this != &other){
    AForm::operator=(other);
    this->target_ = other.target_;
  }
  #ifdef LOG
  std::cout
    << GRNB << "🌳 Constructor ShrubberyCreationForm by assign"
    << RESET << "\n";
  #endif
  return *this;
}

/* ================================= Getter ================================= */

const std::string &ShrubberyCreationForm::get_target() const {
  return this->target_;
}

/* ================================= Setter ================================= */

void ShrubberyCreationForm::set_target(const std::string target){
  if (target.empty() == false)
    this->target_ = target;
}

/* =============================== Functions ================================ */

/**
 * @brief Execute the Shrubs creation
 * @param executor Bureaucrate that will execute the form
 * @note If bureaucrate grade is greater than form exec grade, a file will be 
 * created and fill with ASCII trees
 * @exception recover from checkExecuteConditions
*/
void  ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
  this->checkExecuteConditions(executor);
  std::ofstream file;
  file.open((target_ + "_shrubbery").c_str());
  if (file.is_open()) {
    file << 
"               ,@@@@@@@,\n"
"       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
"    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
"   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
"   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
"   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
"   `&%\\ ` /%&'    |.|        \\ '|8'\n"
"       |o|        | |         | |\n"
"       |.|        | |         | |\n"
"jgs \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_\";\n";
    file.close();
    if (file.fail()) {
        std::cerr
          << "Error occurred while closing the file "
          << target_ + "_shrubbery" << '\n';
    } else {
      std::cout 
      << BGRN << "File " + target_ + "_shrubbery created"
      << RESET << "\n";
    }
  } else {
      std::cerr << "Unable to open file " << target_ + "_shrubbery" << '\n';
  }
}
