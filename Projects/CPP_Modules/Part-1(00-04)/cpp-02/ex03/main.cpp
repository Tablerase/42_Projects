/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:11:05 by rcutte            #+#    #+#             */
/*   Updated: 2024/04/13 09:27:45 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Fixed.hpp"
#include "Point.hpp"

int main( void ) {
  Point a(2, 2);
  Point b(2, 7);
  Point c(8, 2);

  Point toFind(4, 4);

  std::cout
    << WHTB << "Points" << RESET << "\n"
    << std::setw(10) << "a: " << a << RESET << "\n"
    << std::setw(10) << "b: " << b << RESET << "\n"
    << std::setw(10) << "c: " << c << RESET << "\n"
    << std::setw(10) << "toFind: " << toFind << RESET << "\n"

    << WHTB << "BSP" << RESET << "\n"
    << (bsp(a, b, c, toFind) ? "In ABC triangle" : "Out of ABC triangle")
    
    << RESET << "\n";
  return 0;
}

