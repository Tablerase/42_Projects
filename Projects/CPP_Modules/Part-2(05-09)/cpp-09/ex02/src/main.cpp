/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:08:20 by rcutte            #+#    #+#             */
/*   Updated: 2024/07/02 14:09:15 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"

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

static bool CheckInput(int ac, char **av, PmergeMe &core){
  try
  {
    // Check amounts of input
    if (ac < 3){ throw std::invalid_argument("Usage: ./PmergeMe [int1] [int2] [...] "); }
    if (ac > MAX_AUTHORIZED_INPUTS + 1) {
      std::ostringstream oss;
      oss << "Too much numbers: input > "
        << MAX_AUTHORIZED_INPUTS 
        << " elements (Ford Johnson Algo inefficient for loads of comparison)";
      throw std::invalid_argument(oss.str());
    }
    // Transform input into integers
    // ⏰ Start time vector/deque fill
    struct timeval start, end;
    gettimeofday(&start, NULL);
    std::vector<int> input_array;
    std::deque<int> input_deque;
    for (size_t i = 1; i < static_cast<size_t>(ac); i++){
      std::string str(av[i]);
      if (isInt(str) == false){ throw std::out_of_range("Invalid input value"); }
      std::istringstream iss(str);
      int num;
      iss >> num;
      if (num < 0){ throw std::invalid_argument("Negative integers are not supported"); }
      if (input_array.empty() != true) {
        for (std::vector<int>::iterator it = input_array.begin(); it != input_array.end() - 1; ++it) {
          if (*it == num) {
            throw std::invalid_argument("Duplicate integers are not supported");
          }
        }
      }
      input_array.push_back(num);
      input_deque.push_back(num);
    }
    // Set array after parsing
    core.set_origin(input_array);
    core.set_vector(input_array);
    core.set_deque(input_deque);
    // ⏰ Stop time vector/deque fill
    gettimeofday(&end, NULL);
    long seconds = end.tv_sec - start.tv_sec;
    long micros = (seconds * 1000000) + end.tv_usec - start.tv_usec;
    core.set_time_vector_init(micros);
    core.set_time_deque_init(micros);
  }
  catch (std::out_of_range& e){
    std::cerr
      << REDB << " ERROR " << RESET << " "
      << "Overflow/type error: " << e.what() << std::endl;
    return false;
  }
  catch (std::exception &e){
    std::cerr
      << REDB << " ERROR " << RESET << " "
      << e.what() << std::endl;
    return false;
  }
  return true;
}

/**
 * @brief Program to sort with ford johnson algo (merge - insert algo)
 * @note Usage of deque and vector: 
 * - random access (vect[index]): allow easier manual operation
 * - efficient with small elements (like int)
 * Difference vector vs deque:
 * - access: vector is fast, deque is a little bit slower
 * - memory: vector use less memory than deque
 * - insert: a little more effective with deque (visible on small amount of elements)
*/
int main(int ac, char **av) {
  PmergeMe core;
  if (CheckInput(ac, av, core) != true){ return EXIT_FAILURE; };

  // Setup algo for Ford Johnson
  try 
  {
    core.SortVector();
    core.SortDeque();
    if (PmergeMe::isSorted(core.get_deque()) == false){
      throw PmergeMe::Unsorted();
    }
    if (PmergeMe::isSorted(core.get_vector()) == false){
      throw PmergeMe::Unsorted();
    }
  }
  catch (std::exception &e){
    std::cerr
      << REDB << " ERROR " << RESET << " "
      << e.what() << std::endl;
    return EXIT_FAILURE;
  }

  // Display result;
  std::cout << core;
}
