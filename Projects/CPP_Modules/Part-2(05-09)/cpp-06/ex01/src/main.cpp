/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:29:56 by rcutte            #+#    #+#             */
/*   Updated: 2024/05/20 15:17:00 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Serializer.hpp"

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
  SeparatorMsg("Source");
  Data test;
  test.school_name = "42 Paris";
  test.year_of_entry = 2023;
  std::cout
    << BBLU << "School name: " << RESET
    << test.school_name << "\n"
    << BMAG << "Promotion: " << RESET
    << test.year_of_entry << "\n";

  SeparatorMsg("Serialization");
  uintptr_t serialized_data = Serializer::serialize(&test);
  std::cout
    << BGRN << "Serialize data: " << RESET
    << serialized_data << "\n";

  SeparatorMsg("Deserialization");
  Data* deserialized_data = Serializer::deserialize(serialized_data);
  std::cout
    << BBLU << "School name: " << RESET
    << deserialized_data->school_name << "\n"
    << BMAG << "Promotion: " << RESET
    << deserialized_data->year_of_entry << "\n";
  SeparatorLine();
}
