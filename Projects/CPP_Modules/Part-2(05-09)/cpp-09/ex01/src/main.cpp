/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:08:20 by rcutte            #+#    #+#             */
/*   Updated: 2024/07/03 01:00:33 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RPN.hpp"

void SeparatorMsg(std::string const &msg){
  int msg_len = msg.length();
  int inter_space = (63 - msg_len) / 2;
  std::cout
    << "╔" << "══════════════════════════════════════════════════════════"
    << "╗" << "\n"
    << "║" << std::setw(inter_space + 1) << std::setfill(' ') << RESET
    << msg ;
  if (msg_len % 2 == 0)
    std::cout << " ";
  std::cout
    << std::setw(inter_space + 1) << "║" << "\n"
    << "╚" << "══════════════════════════════════════════════════════════"
    << "╝" << "\n";
}

// Check input (ac==2, check if there is invalid values in av)

int main(int ac, char** av) {
  RPN core;
  try
  {
    CheckInput(ac, av, core);
    Calculation(core);
    std::cout
      << CYNB << " " << core.equation_ << " " << RESET
      << " = "
      << GRNB << " " << core.value_ << " " << RESET
      << std::endl;
  }
  catch(const std::exception& e)
  {
    std::cerr
      << REDB << " ERROR " << RESET << " "
      << e.what() << std::endl;
    return EXIT_FAILURE;
  } 
}
