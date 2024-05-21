/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:29:56 by rcutte            #+#    #+#             */
/*   Updated: 2024/05/19 21:37:08 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"

static void checkArgs(int ac, char *av[]){
  if (ac != 2) {
    std::cerr
      << REDB << "ERROR" << RESET << " "
      << "Invalid amount of arguments: "
      << BRED << ac - 1 << RESET << "\n";
    exit(EXIT_FAILURE);
  }
  std::string check = av[1];
  if (check.empty() == true) {
    std::cerr
      << REDB << "ERROR" << RESET << " "
      << "Empty argument"
      << RESET << "\n";
    exit(EXIT_FAILURE);
  }
  if (check.length() == 1 && std::isprint(check[1]) == 1) {
    std::cerr
      << REDB << "ERROR" << RESET << " "
      << "Non displayable argument is not accepted"
      << RESET << "\n";
      exit(EXIT_FAILURE);
  }
};

int main(int ac, char *av[]){
  // Test
  checkArgs(ac, av);
  std::string input = av[1];
  ScalarConverter::convert(input);

  // std::string char_str = "*";
  // ScalarConverter::convert(char_str);

  // std::string i_int = "0";
  // ScalarConverter::convert(i_int);
  // std::string i_min_str = "-2147483648";
  // ScalarConverter::convert(i_min_str);
  // std::string i_max_str = "2147483647";
  // ScalarConverter::convert(i_max_str);

  // std::string f_min_str = "1.17549e-38";
  // ScalarConverter::convert(f_min_str);
  // std::string f_max_str = "3.40282e+38";
  // ScalarConverter::convert(f_max_str);
  // ScalarConverter::convert("nanf");
  // ScalarConverter::convert("-inff");
  // ScalarConverter::convert("+inff");
  
  // std::string d_max_str = "1.79769e+308";
  // ScalarConverter::convert(d_max_str);
  // std::string d_min_str = "2.22507e-308";
  // ScalarConverter::convert(d_min_str);
  // ScalarConverter::convert("nan");
  // ScalarConverter::convert("-inf");
  // ScalarConverter::convert("+inf");

  // std::string test_str = "1.8e308";
  // ScalarConverter::convert(test_str);
}
