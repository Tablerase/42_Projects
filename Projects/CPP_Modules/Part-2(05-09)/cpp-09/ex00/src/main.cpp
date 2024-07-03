/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:08:20 by rcutte            #+#    #+#             */
/*   Updated: 2024/07/02 02:30:33 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"

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

int main(int ac, char **av) {
  BitcoinExchange core;
  try
  {
    InitExchange(ac, av, core);
    InitCoinMap(core);
    SeparatorMsg("BitCoin Exchange");
    BitcoinDisplay(core);
  }
  catch(const std::exception& e)
  {
    std::cerr
      << REDB << " ERROR " << RESET << " "
      << e.what() << std::endl;
    return EXIT_FAILURE;
  } 
}
