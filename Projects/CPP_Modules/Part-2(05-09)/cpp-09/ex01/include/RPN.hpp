/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:30:51 by rcutte            #+#    #+#             */
/*   Updated: 2024/07/03 01:11:07 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_H_
# define RPN_H_

# include <iostream>
# include <iomanip>
# include <algorithm>
# include <exception>
# include <cstdlib>
# include <string>

# include <stack>
# include <fstream>
# include <sstream>
# include "color.h"

# define OPERATOR_CHAR "+-*/"
# define NUMBERS "0123456789"
# define ALLOWED_CHAR "0123456789+-*/ "

/**
 * @note Input numbers : < 10, integers only
 * stack : allow to pile numbers like how the Reverse Polish Calculate
 * the operations
 * 
 * https://en.wikipedia.org/wiki/Reverse_Polish_notation#Explanation
 */

struct RPN
{
  std::string         equation_;
  double              value_;
  std::stack<double>  stack_;
};

// Check Inputs

void CheckInput(int ac, char** av, RPN& core);

// Functions

void Calculation(RPN& core);

#endif