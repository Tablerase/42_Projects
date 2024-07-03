/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:30:57 by rcutte            #+#    #+#             */
/*   Updated: 2024/07/03 19:00:54 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ================================  Header ================================= */

#include "../include/RPN.hpp"

/* ======================== Constructor / Destructor ======================== */

void  CheckInput(int ac,char** av, RPN& core){
  if (ac != 2){
    throw std::runtime_error("[Usage] ./RPN [RPN calculation]\n\t[Example] ./RPN \"7 7 * 7 -\"");
  }
  std::string input(av[1]);
  // Check empty input
  if (input.empty()){ throw std::runtime_error("Empty program argument"); }
  // Check for not supported char
  size_t pos = input.find_first_not_of(ALLOWED_CHAR);
  if (pos != input.npos){
    if (input.at(pos) == '.'){
      throw std::runtime_error("Decimals unsupported");
    }
    throw std::runtime_error("Input contains unsupported characters"); 
  }
  // Check if last element is an operator
  std::string input_reverse(input);
  std::reverse(input_reverse.begin(), input_reverse.end());
  std::istringstream sstream(input_reverse);
  std::string last_element;
  if (std::getline(sstream, last_element, ' ')){
    size_t pos = last_element.find_first_not_of(OPERATOR_CHAR);
    if (pos != last_element.npos){ throw std::runtime_error("Not a RPN format: " + input); }
  }
  // Assign
  core.equation_ = input;
}

/* ================================ Function ================================ */

/**
 * @brief Calculate RPN equation
 * @param core structure to store stack, string equation, value
 * @note Perform operation in stack order.
 * left-to-right evaluation of RPN. numbers are push to stack then pop before
 * operation the result of each operation is push to the stack and that continue
 * till the end of the equation (left to right).
 * @example                                         Stack
 * 3 4 +  ==> 3 push                                3
 * 4 +    ==> 4 push                                4 3
 * +      --> operand2(pop 4) operand1(pop 3)       .
 *        --> operand1(3) + operand2(4)             .
 *        ==> result(7) push                        7
 * @ref https://en.wikipedia.org/wiki/Reverse_Polish_notation#Explanation
 */
void Calculation(RPN& core){
  std::istringstream sstream(core.equation_);
  std::string element;
  // Iterate over each element in the equation
  while (sstream >> element)
  {
    #ifdef LOG
    std::cout << "Element: " << element << std::endl;
    #endif
    double element_num;
    // Handle numbers
    if (std::istringstream(element) >> element_num){
      if (element_num >= 10 || element_num == 0 || element_num <= -10){
        throw std::runtime_error("Unsupported number");
      }
      core.stack_.push(element_num);
    } else { // Handle operators
      double first_operand, second_operand;
      // recover operands on the stack
      if (core.stack_.size() >= 2){
        second_operand = core.stack_.top();
        core.stack_.pop();
        first_operand = core.stack_.top();
        core.stack_.pop();
      } else {
        throw std::runtime_error("Invalid RPN format: " + core.equation_);
      }
      // apply operator with operands
      if (element == "*"){
        core.stack_.push(first_operand * second_operand);
      } else if (element == "/"){
        core.stack_.push(first_operand / second_operand);
      } else if (element == "+"){
        core.stack_.push(first_operand + second_operand);
      } else if (element == "-"){
        core.stack_.push(first_operand - second_operand);
      } else {
        throw std::runtime_error("Error");
      }
      #ifdef LOG
      std::cout << "Value: " << core.stack_.top() << std::endl;
      #endif
    }
  }
  core.value_ = core.stack_.top();
}
