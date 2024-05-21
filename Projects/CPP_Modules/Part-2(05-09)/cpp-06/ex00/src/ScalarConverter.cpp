/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:31:39 by rcutte            #+#    #+#             */
/*   Updated: 2024/05/19 21:34:52 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"

/* ======================== Constructor / Destructor ======================== */

ScalarConverter::ScalarConverter(){}
ScalarConverter::ScalarConverter(const ScalarConverter &other){ (void)other; }
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs){
  (void)rhs;
  return *this;
}
ScalarConverter::~ScalarConverter(){}

/* =============================== Functions ================================ */

static int stringToInt(const std::string &input){
  std::stringstream ss(input);
  int num;
  ss >> num;
  return num;
}

static float stringToFloat(const std::string &input){
  std::stringstream ss(input);
  float num;
  ss >> num;
  return num;
}

static double stringToDouble(const std::string &input){
  std::stringstream ss(input);
  double num;
  ss >> num;
  return num;
}

static bool isSpecialValues(const std::string &input){
  std::string specialTypes[6] = {
		"-inff", "+inff", "nanf",
		"-inf", "+inf", "nan"
	};

  for (int i = 0; i < 6; i++){
    if (input == specialTypes[i])
      return true;
  }
  return false;
}

static void convertError(const std::string input){
  std::cerr
    << REDB << "ERROR" << RESET << " "
    << "Argument: " << BRED << input
    << RESET << " is not an accepted scalar type (int, float, double, char)\n";
  (void)input;
}

void  ScalarConverter::convert(const std::string input){
  // get input type
  e_type type = getType(input);
  if (type == E_ERROR)
    return convertError(input);
  SeparatorLine();
  std::cout
    << BWHT << input << RESET
    << " is a " << BBLU << outputType(type) << RESET << "\n";

  int i_output;
  float f_output;
  double d_output;
  std::string c_output;

  // char
  if (type == E_CHAR){
    i_output = static_cast<int>(input[0]);
    f_output = static_cast<float>(input[0]);
    d_output = static_cast<double>(input[0]);
    std::cout 
      << "char: " << "'" << input[0] << "'" << "\n"
      << "int: " << i_output << "\n"
      << "float: " << f_output << ".0f" << "\n"
      << "double: " << d_output << ".0" << "\n";
  } // numbers
  else {
    // check specialVal
    if (isSpecialValues(input)){
      c_output = "impossible";
      if (type == E_FLOAT) {
        std::cout << "char: " << c_output << "\n"
          << "int: " << c_output << "\n"
          << "float: " << input << "\n"
          << "double: " << input.substr(0, input.length() - 1) << "\n";
      } else {
        std::cout << "char: " << c_output << "\n"
          << "int: " << c_output << "\n"
          << "float: " << input + "f" << "\n"
          << "double: " << input  << "\n";
      }
      return;
    }
    // get standard values
    if (type == E_INT) {
      i_output = stringToInt(input);
      f_output = static_cast<float>(i_output);
      d_output = static_cast<double>(i_output);
    } else if (type == E_FLOAT) {
      f_output = stringToFloat(input);
      i_output = static_cast<int>(f_output);
      d_output = static_cast<double>(f_output);
    } else {
      d_output = stringToDouble(input);
      i_output = static_cast<int>(d_output);
      f_output = static_cast<float>(d_output);
    }
    // char (float and double)
    if (d_output >= std::numeric_limits<char>::min()
      && d_output <= std::numeric_limits<char>::max()){
      if (std::isprint(i_output)){
        c_output = static_cast<char>(i_output);
        c_output = "'" + c_output + "'";
      } else if (d_output >= 0 && d_output <= 127) {
        c_output = "Non displayable";
      } else {
        c_output = "impossible";
      }
    } else {
      c_output = "impossible";
    }
    std::cout << "char: " << c_output << "\n";
    // num
    if (type != E_INT 
      && (i_output == 0 || i_output == std::numeric_limits<int>::min())){
        std::cout << "int: " << "impossible" << "\n";
    } else {
      std::cout << "int: " << i_output << "\n";
    }
    if (d_output - static_cast<long long>(d_output) == 0) { // when floating part equal 0
			std::cout << "float: " << f_output << ".0f" << "\n";
			std::cout << "double: " << d_output << ".0" << "\n";
		} else {
      if (type != E_FLOAT && (f_output == 0 || f_output == std::numeric_limits<float>::min())){
        std::cout << "float: " << "impossible" << "\n";
			  std::cout << "double: " << d_output << "\n";
      } else {
        std::cout << "float: " << f_output << "f" << "\n";
			  std::cout << "double: " << d_output << "\n";
      }
		}
  }
}
