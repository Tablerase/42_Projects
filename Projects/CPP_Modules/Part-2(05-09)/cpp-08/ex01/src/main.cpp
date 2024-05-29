/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:08:20 by rcutte            #+#    #+#             */
/*   Updated: 2024/05/26 17:24:26 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Span.hpp"

void AddElement(Span &container, int value){
  try {
    container.addNumber(value);
  } catch (std::exception &e){
    std::cerr
    << REDB << " ERROR " << RESET
    << " " << e.what() << std::endl;
  }
}

void AddElements(Span &container, unsigned int amount, int value){
  try {
    container.addNumbers(amount, value);
  } catch (std::exception &e){
    std::cerr
    << REDB << " ERROR " << RESET
    << " " << e.what() << std::endl;
  }
}

void AddElements(Span &container, int start_value, int end_value, int increment){
  try {
    container.addNumbers(start_value, end_value, increment);
  } catch (std::exception &e){
    std::cerr
    << REDB << " ERROR " << RESET
    << " " << e.what() << std::endl;
  }
}

void AddRandom(Span &container, unsigned int amount){
  srand(time(0));
  try {
    for(unsigned int i = 0; i < amount; ++i) {
      container.addNumber(rand()); // Add a random number to the container
    }
  } catch (std::exception &e){
    std::cerr
    << REDB << " ERROR " << RESET
    << " " << e.what() << std::endl;
  }
}

void CheckShortSpan(Span &container){
  try {
    unsigned int span = container.shortestSpan();
    std::cout << BLU << span << RESET << std::endl;
  } catch (std::exception &e){
    std::cerr
      << REDB << " ERROR " << RESET
      << " " << e.what() << std::endl;
  }
}

void CheckLongSpan(Span &container){
  try {
    unsigned int span = container.longestSpan();
    std::cout << BLU << span << RESET << std::endl;
  } catch (std::exception &e){
    std::cerr
      << REDB << " ERROR " << RESET
      << " " << e.what() << std::endl;
  }
}

int main( void ) {
  {
    SeparatorMsg("Default Span");
    Span test;
    std::cout << test << std::endl;
      
    SeparatorMsg("Fill Span");
    Span test_10(10);
    for (int i = 0; i < 10; i++) test_10.addNumber(i);
    std::cout << test_10 << std::endl;
    
    SeparatorMsg("Test Outrange");
    AddElement(test_10, 10);

    SeparatorMsg("Big Fill");
    Span test_100(100);
    AddElements(test_100, 100, 10);
    std::cout << test_100 << std::endl;
    Span test_to_fill = test_100;
    std::cout << test_to_fill << std::endl;
  }
  {
    Span test_zero_span(10000);
    Span test_random(10000);
    Span test_random_small(100);
    AddElements(test_zero_span, 10000, 1);
    AddRandom(test_random, 10000);
    AddRandom(test_random_small, 100);
    SeparatorMsg("Shortest Span");
    
    std::cout << "Shortest no span: ";
    CheckShortSpan(test_zero_span);
    std::cout << "Shortest span (few numbers): ";
    CheckShortSpan(test_random_small);
    std::cout << "Shortest span: ";
    CheckShortSpan(test_random);
    SeparatorLine();
    Span test_error(1);
    CheckShortSpan(test_error);
  }
  {
    Span test_zero_span(10000);
    Span test_random(10000);
    Span test_random_small(100);
    AddElements(test_zero_span, 10000, 1);
    AddRandom(test_random, 10000);
    AddRandom(test_random_small, 100);
    SeparatorMsg("Longest Span");
    
    std::cout << "Longest no span: ";
    CheckLongSpan(test_zero_span);
    std::cout << "Longest Span (few numbers): ";
    CheckLongSpan(test_random_small);
    std::cout << "Longest Span: ";
    CheckLongSpan(test_random);
    SeparatorLine();
    Span test_error(1);
    CheckLongSpan(test_error);
  }
  {
    SeparatorMsg("Display Span");
    Span test_display(1000);
    AddElements(test_display, 1, 1000, 5);
    std::cout << test_display << std::endl;
    std::cout << "Longest span: ";
    CheckLongSpan(test_display);
    std::cout << "Shortest span: ";
    CheckShortSpan(test_display);
  }
}

/* Subject main */

// int main()
// {
//   Span sp = Span(5);
//   sp.addNumber(6);
//   sp.addNumber(3);
//   sp.addNumber(17);
//   sp.addNumber(9);
//   sp.addNumber(11);
//   std::cout << sp.shortestSpan() << std::endl;
//   std::cout << sp.longestSpan() << std::endl;
//   return 0;
// }