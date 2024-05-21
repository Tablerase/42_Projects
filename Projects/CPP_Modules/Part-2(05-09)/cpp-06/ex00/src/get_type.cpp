/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:05:39 by rcutte            #+#    #+#             */
/*   Updated: 2024/05/19 21:40:33 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"

static std::string floatToString(const float input){
  std::ostringstream oss;
  oss << input;
  std::string result = oss.str();
  return result;
}

static std::string doubleToString(const double input){
  std::ostringstream oss;
  oss << input;
  std::string result = oss.str();
  return result;
}

static std::string longDoubleToString(const long double input){
  std::ostringstream oss;
  oss << input;
  std::string result = oss.str();
  return result;
}

static bool isInt(const std::string& str) {
  // transform to int
  std::istringstream iss(str);
  int n;
  iss >> n;
  // transform to long to check for overflow
  std::istringstream iss_l(str);
  long l;
  iss_l >> l;
  return iss.eof() && !iss.fail() && (n == l);
}

static bool isFloat(const std::string& str) {
  bool result = false;
  // check special values
  if (str == "nanf" || str == "-inff" || str == "+inff")
    return true;
  // transform str to float
  std::istringstream iss(str);
  float f;
  iss >> f;
  // transform str to double to check for overflow
  std::istringstream iss_d(str);
  double d;
  iss_d >> d;
  // find if str is float
  char last = str[str.length() - 1];
  if (f != 0){
    if (last == 'f' || last == 'F'){
      result = !iss.fail() && (iss.tellg() == (long)str.length() - 1);
    } else { // check if transform succeed and if number dont overflow
      result = iss.eof() && !iss.fail() && (floatToString(f) == doubleToString(d));
    }
  } else if (str == "0.0f" || str == "0.0F") {
    result = true;
  }
  return result;
}


static bool isDouble(const std::string& str) {
  // check special values
  if (str == "nan" || str == "-inf" || str == "+inf")
    return true;
  // transform to double
  std::istringstream iss(str);
  double d;
  iss >> d;
  // transfrom to long double to check for overflow
  std::istringstream iss_ld(str);
  long double ld;
  iss_ld >> ld;
  return iss.eof() && !iss.fail() && (doubleToString(d) == longDoubleToString(ld));
}

e_type getType(std::string input){
  if (isInt(input)){
    return E_INT;
  }
  if (isFloat(input)){
    return E_FLOAT;
  }
  if (isDouble(input)){
    return E_DOUBLE;
  }
  if (input.length() == 1){
    return E_CHAR;
  }
  return E_ERROR;
}

std::string outputType(const e_type type){
  switch (type)
  {
  case E_INT:
    return "integer";
  case E_FLOAT:
    return "float";
  case E_DOUBLE:
    return "double";
  case E_CHAR:
    return "char";
  default:
    return "type not found";
  }
}

#define SEPARATOR_LENGHT 60

void SeparatorLine(){
  std::cout
    << BLU
    << std::setw(SEPARATOR_LENGHT) << std::setfill('-')
    << RESET << "\n";
}
