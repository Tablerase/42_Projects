/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:24:29 by rcutte            #+#    #+#             */
/*   Updated: 2024/05/19 21:40:38 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_H_
#define SCALARCONVERTER_H_

# include <iostream>
# include <string>
# include <sstream>
# include <stdexcept>
# include <iomanip>
# include <cstdlib>
# include <limits>
# include "color.h"

class ScalarConverter
{
private:
  ScalarConverter();
  ScalarConverter(const ScalarConverter &other);
  ScalarConverter &operator=(const ScalarConverter &rhs);

public:
  ~ScalarConverter();
  static void convert(const std::string input);
};

enum e_type {
  E_CHAR,
  E_INT,
  E_FLOAT,
  E_DOUBLE,
  E_ERROR
};

void SeparatorLine();

e_type getType(std::string input);
std::string outputType(const e_type type);

#endif