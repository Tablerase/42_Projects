/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 18:29:09 by rcutte            #+#    #+#             */
/*   Updated: 2024/04/23 14:38:07 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include "Phonebook.hpp"

Phonebook::Phonebook() : contacts_max_amount_(8) {
  contacts_amount_ = 0;
}

Phonebook::~Phonebook() {
}

/* ######################## ADD ######################## */

/**
 * @brief Get a non empty input from user
 * @return Non empty string
 * @note Ensure the user input a non empty string, ws allow to insert space into
 * the input. empty check len size.
*/
static std::string GetInput(std::string msg){
  std::string input;
  while (true)
  {
    std::cout << std::setw(PHONE_INPUT_PADDING) << msg;
    std::getline(std::cin, input);
    if (!input.empty())
      break;
    else
      std::cout << "Invalid input. Please enter a non-empty string\n";
  }
  return input;
}

static void PhoneGetInputs(Contact *tmp){
  tmp->setFirstName(GetInput("First Name: "));
  tmp->setLastName(GetInput("Last Name: "));
  tmp->setNickName(GetInput("Nickname: "));
  tmp->setPhoneNum(GetInput("Phone number: "));
  tmp->setDarkestSecret(GetInput("Darkest Secret: "));
}

void  Phonebook::PhoneAdd(){
  Contact *tmp;
  if (contacts_amount_ >= contacts_max_amount_)
  {
    tmp = &contact_array_[contacts_max_amount_ - 1];
  }
  else 
  {
    tmp = &contact_array_[contacts_amount_];
    contacts_amount_++;
  }
  PhoneGetInputs(tmp);
}

/* ######################## SEARCH ######################## */

static std::string cropString(std::string tocrop){
  if (tocrop.length() > 10)
  {
    tocrop.resize(9);
    tocrop.resize(10, '.');
  }
  return tocrop;
}

void Phonebook::PhoneGrid(){
  std::cout << "#############################################" << "\n";
  std::cout << "|" << std::setw(10) << "Index";
  std::cout << "|" << std::setw(10) << "FirstName";
  std::cout << "|" << std::setw(10) << "LastName";
  std::cout << "|" << std::setw(10) << "Nickname";
  std::cout << "|\n";
  std::cout << "#############################################" << "\n";
  for (int i = 0; i < this->contacts_amount_; i++)
  {
    std::cout << "|" << std::setw(10) << i;
    std::cout << "|" << std::setw(10) << cropString(this->contact_array_[i].getFirstName());
    std::cout << "|" << std::setw(10) << cropString(this->contact_array_[i].getLastName());
    std::cout << "|" << std::setw(10) << cropString(this->contact_array_[i].getNickName());
    std::cout << "|\n";
  }
  std::cout << "\n";
}

int stringToInt(const std::string &str) {
    std::stringstream ss(str);
    int num;
    ss >> num;
    return num;
}

void  Phonebook::PhoneSelection(){
  std::string str;
  int input;
  while (true)
  {
    std::cout << "Search by index: ";
    std::getline(std::cin, str);
    if (std::cin.eof())
      return;
    try {
      input = stringToInt(str);
      if (input >= 0 && input < this->contacts_amount_)
        break;
      else
        std::cout << BRED << "\nIndex out of range: " << RESET << 0 << "-" << this->contacts_amount_ - 1 << "\n";
    } catch (std::invalid_argument& e) {
      std::cout << BRED << "\n Invalid argument. Pls use an integer\n";
    } catch (std::out_of_range& e) {
      std::cout << BRED << "\nIndex out of range: " << RESET << 0 << "-" << this->contacts_amount_ - 1 << "\n";
    }
  }
  std::cout << BCYN << std::setw(COLUMN_HEADER_WIDTH) << "First Name: " << RESET
    << this->contact_array_[input].getFirstName() << "\n";
  std::cout << BCYN << std::setw(COLUMN_HEADER_WIDTH) << "Last Name: " << RESET
    << this->contact_array_[input].getLastName() << "\n";
  std::cout << BCYN << std::setw(COLUMN_HEADER_WIDTH) << "Nick Name: " << RESET
    << this->contact_array_[input].getNickName() << "\n";
  std::cout << BCYN << std::setw(COLUMN_HEADER_WIDTH) << "Phone Numbers: " << RESET
    << this->contact_array_[input].getPhoneNum() << "\n";
  std::cout << BCYN << std::setw(COLUMN_HEADER_WIDTH) << "Darkest Secret: " << RESET
    << this->contact_array_[input].getDarkestSecret() << "\n";
}

void Phonebook::PhoneSearch(){
  if (this->contacts_amount_ == 0)
  {
    std::cout << BRED << "No saved contact\n" << RESET;
    return ;
  }
  PhoneGrid();
  PhoneSelection();
}
