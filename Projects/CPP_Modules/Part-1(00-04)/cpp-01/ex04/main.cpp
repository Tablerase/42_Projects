/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 18:59:00 by rcutte            #+#    #+#             */
/*   Updated: 2024/05/15 19:10:18 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "color.h"

void  checkArgs(int ac, char **av) {
  if (ac != 4)
  {
    std::cerr 
      << BRED << "Invalid amount of args\n" << RESET
      << YEL << "Usage: "
      << RESET "./replacer [filename] [string_from] [string_to]\n";
    exit(EXIT_FAILURE);
  }
  (void)av;
}

bool replaceStringInFile(
  std::string const &filename,
  std::string const &to_find,
  std::string const &replacement) {
    
  std::ifstream fileIn;
  fileIn.open(filename.c_str());
  if (!fileIn.is_open()) {
    std::cerr << BRED << "Failed to open file: " << RESET << filename << "\n";
    return false;
  }

  std::string buffer;
  std::string line;
  size_t pos;
  while (std::getline(fileIn, line))
  {
    pos = 0;
    while ((pos = line.find(to_find, pos)) != std::string::npos)
    {
      line.erase(pos, to_find.length());
      line.insert(pos, replacement);
      pos += replacement.length();
    }
    buffer.append(line);
    if (!fileIn.eof())
      buffer.append("\n");
  }
  
  std::ofstream fileOut;
  fileOut.open((filename + ".replace").c_str());
  if (!fileOut.is_open()) {
    std::cerr 
      << BRED << "Failed to open/create file: "
      << RESET << filename + ".replace" << "\n";
    return false;
  }
  
  fileOut << buffer;
  
  // IOS auto close at function leave
  // fileOut.close();
  // if (fileOut.fail()) {
  //   std::cerr 
  //     << BRED << "Failed to close outfile: "
  //     << RESET << filename + ".replace" << "\n";
  //   return false;
  // }
  // Fails cursor pos = -1
  // fileIn.close();
  // if (fileIn.fail()){
  //   std::cerr
  //     << BRED << "Failed to close infile: "
  //     << RESET << filename << "\n";
  //   return false;
  // }
  return true;
}

int main(int ac, char **av)
{
  checkArgs(ac, av);
  if (replaceStringInFile(av[1], av[2], av[3]) == false)
    return EXIT_FAILURE;

  return 0;
}