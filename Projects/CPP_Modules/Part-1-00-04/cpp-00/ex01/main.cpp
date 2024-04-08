/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 20:51:29 by rcutte            #+#    #+#             */
/*   Updated: 2024/04/08 15:09:35 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "color.h"
#include "Phonebook.hpp"

int main()
{
  Phonebook phonebook_inst;

  std::cout << BMAG << "📞 Welcome to this Awesome Phonebook 📞" << RESET << "\n";
  std::cout << BGRN << std::setw(8) << "ADD" << " : Add a contact" << RESET << "\n";
  std::cout << BYEL << std::setw(8) << "SEARCH" << " : Search contact" << RESET << "\n";
  std::cout << BRED << std::setw(8) << "EXIT" << " : Exit the Phonebook" << RESET << "\n";

  std::string input;
  while (true)
  {
    if (std::cin.eof())
      return 0;
    std::cout << "📞 > ";
    std::getline(std::cin >> std::ws, input);
    if (input == "ADD") {
      phonebook_inst.PhoneAdd();
    } else if (input == "SEARCH") {
      phonebook_inst.PhoneSearch();
    } else if (input == "EXIT") {
      break;
    } else {
      std::cout << BRED << "Invalide Command (available: ADD, SEARCH, EXIT)" << RESET << "\n";
    }
  }
  return 0;
}