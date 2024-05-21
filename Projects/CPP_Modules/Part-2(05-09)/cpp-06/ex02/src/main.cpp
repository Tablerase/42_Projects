/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:29:56 by rcutte            #+#    #+#             */
/*   Updated: 2024/05/20 16:24:48 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Types.hpp"

#define SEPARATOR_LENGHT 60

void SeparatorLine(){
  std::cout
    << BLU
    << std::setw(SEPARATOR_LENGHT) << std::setfill('-')
    << RESET << "\n";
}

void SeparatorMsg(std::string msg){
  int msg_len = msg.length();
  int inter_space = (SEPARATOR_LENGHT - msg_len) / 2;
  std::cout
    << std::setw(SEPARATOR_LENGHT) << std::setfill('=') << "\n"
    << "|" << std::setw(inter_space + 1) << std::setfill(' ') << RESET
    << msg ;
  if (msg_len % 2 == 1)
    std::cout << " ";
  std::cout
    << std::setw(inter_space + 1) << "|" << "\n"
    << std::setw(SEPARATOR_LENGHT) << std::setfill('=') << "\n";
}

int main(){
  srand(time(0)); // init random seed
  SeparatorMsg("Generate");
  Base *ptr0 = generate();
  Base *ptr1 = generate();
  Base *ptr2 = generate();
  
  SeparatorMsg("Identify");
  identify(ptr0);
  identify(ptr1);
  identify(ptr2);
  SeparatorLine();
  identify(*ptr0);
  identify(*ptr1);
  identify(*ptr2);
  delete ptr0;
  delete ptr1;
  delete ptr2;
}
