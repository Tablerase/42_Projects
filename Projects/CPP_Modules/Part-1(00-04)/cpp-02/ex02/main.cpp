/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:11:05 by rcutte            #+#    #+#             */
/*   Updated: 2024/04/12 01:40:21 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void ) {
  Fixed a (42.0f);
  Fixed const b( 10.42f );
  Fixed c( 3.14f );

  std::cout
    << WHTB << "Operations" << RESET << "\n"

    << MAGB << "+" << RESET
    << " a= " << a << " b= " << b
    << " a+b= " << a + b << "\n"

    << MAGB << "-" << RESET
    << " a= " << a << " b= " << b
    << " a-b= " << a - b<< "\n"

    << MAGB << "*" << RESET
    << " a= " << a << " b= " << b
    << " a*b= " << a * b << "\n"
  
    << MAGB << "/" << RESET
    << " a= " << a << " b= " << b
    << " a/b= " << a / b << "\n"

    << WHTB << "Comparators" << RESET << "\n"

    << MAGB << "==" << RESET
    << " a= " << a << " c= " << c
    << " a==c " << ((a == c) ? "true" : "false") << "\n"

    << MAGB << "!=" << RESET
    << " a= " << a << " c= " << c
    << " a!=c " << ((a != c) ? "true" : "false") << "\n"

    << MAGB << ">" << RESET
    << " a= " << a << " c= " << c
    << " a>c " << ((a > c) ? "true" : "false") << "\n"

    << MAGB << ">=" << RESET
    << " a= " << a << " c= " << c
    << " a>=c " << ((a >= c) ? "true" : "false") << "\n"

    << MAGB << "<" << RESET
    << " a= " << a << " c= " << c
    << " a<c " << ((a < c) ? "true" : "false") << "\n"

    << MAGB << "<=" << RESET
    << " a= " << a << " c= " << c
    << " a<=c " << ((a <= c) ? "true" : "false") << "\n"

    << WHTB << "Incrementation " << RESET << "\n"
    
    << MAGB << "++x" << RESET
    << " a= " << a
    << " ++a " << ++a << "\n"
    
    << MAGB << "x++" << RESET
    << " a= " << --a
    << " a++ " << a++ << "\n"

    << WHTB << "Decrementation " << RESET << "\n"
    
    << MAGB << "--x" << RESET
    << " c= " << c
    << " --c " << --c << "\n"
    
    << MAGB << "x--" << RESET
    << " c= " << ++c
    << " c-- " << c-- << "\n"

    << WHTB << "Extremity Min/Max" << RESET << "\n"
    << " a= " << a << " b= " << b
    << " min= " << Fixed::min(a, b) << "\n"

    << " a= " << a << " b= " << b
    << " max= " << Fixed::max(a, b) << "\n"

    << RESET << "\n";
  return 0;
}

// int main( void ) {
//   Fixed a;
//   Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
//   std::cout << a << std::endl;
//   std::cout << ++a << std::endl;
//   std::cout << a << std::endl;
//   std::cout << a++ << std::endl;
//   std::cout << a << std::endl;
//   std::cout << b << std::endl;
//   std::cout << Fixed::max( a, b ) << std::endl;
//   return 0;
// }
