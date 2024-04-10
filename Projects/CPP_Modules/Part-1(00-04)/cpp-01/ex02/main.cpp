/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:39:03 by rcutte            #+#    #+#             */
/*   Updated: 2024/04/08 17:27:58 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

#include "color.h"

#define PADDING_INFO 30

int main()
{
  std::string source = "HI THIS IS BRAIN"; // Source
  std::string *stringPTR = &source; // Pointer
  std::string &stringREF = source; // Ref

  std::cout << WHTB << "Memory Address" << RESET << "\n";

  std::cout
    << std::setw(PADDING_INFO)
    << "Address of source: "
    << BMAG << static_cast<void *>(&source) << RESET << "\n"
    << std::setw(PADDING_INFO)
    << "Address of pointer: "
    << BGRN << static_cast<void *>(&stringPTR) << RESET << "\n"
    << std::setw(PADDING_INFO)
    << "Address point by pointer: "
    << BMAG << static_cast<void *>(stringPTR) << RESET << "\n"
    << std::setw(PADDING_INFO)
    << "Address of reference: "
    << BMAG << static_cast<void *>(&stringREF)
    << RESET << "\n";

  std::cout << WHTB << "Values" << RESET << "\n";

  std::cout
    << std::setw(PADDING_INFO)
    << "Value of source: "
    << BMAG << source << RESET << "\n"
    << std::setw(PADDING_INFO)
    << "Value in pointer: "
    << BGRN << stringPTR << RESET << "\n"
    << std::setw(PADDING_INFO)
    << "Value point by pointer: "
    << BMAG << *stringPTR << RESET << "\n"
    << std::setw(PADDING_INFO)
    << "Value point by ref: "
    << BMAG << stringREF << RESET << "\n"; // Deref by default
}
