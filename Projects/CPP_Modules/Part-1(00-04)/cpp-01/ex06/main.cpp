/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:30:59 by rcutte            #+#    #+#             */
/*   Updated: 2024/04/09 20:30:52 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Harl.hpp"

void  checkArgs(int ac, char **av) {
  if (ac != 2) {
    std::cerr
      << BRED << "Invalid Amount of Arguments" << RESET << "\n"
      << BYEL << "Usage (DEBUG, INFO, WARNING, ERROR): "
      << RESET << "./harl_filter LEVEL" << "\n";
    exit(EXIT_FAILURE);
  }
}

int main(int ac, char **av)
{
  checkArgs(ac, av);
  Harl veteran_eater{};
  if (veteran_eater.setMinComplain(av[1]) == false)
    return EXIT_FAILURE;

  std::cout
    << WHTB << "Harl is in the Restaurant" << RESET << "\n";
  veteran_eater.complain("Hello There !");
  
  std::cout 
    << WHTB << "Harl starts Complaining" << RESET << "\n";
  veteran_eater.complain("DEBUG");
  veteran_eater.complain("INFO");
  veteran_eater.complain("WARNING");
  veteran_eater.complain("ERROR");

  return EXIT_SUCCESS;
}
