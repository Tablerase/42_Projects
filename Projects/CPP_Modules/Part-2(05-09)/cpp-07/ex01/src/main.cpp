/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:08:20 by rcutte            #+#    #+#             */
/*   Updated: 2024/05/22 16:26:37 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/iter.hpp"

#define SEPARATOR_LENGHT 60

// Mandatory Test

void SeparatorLine(){
  std::cout
    << BLU
    << std::setw(SEPARATOR_LENGHT) << std::setfill('-')
    << RESET << "\n";
}

void SeparatorMsg(std::string msg){
  int msg_len = msg.length();
  int inter_space = (SEPARATOR_LENGHT - msg_len) / 2;
  std::cout
    << std::setw(SEPARATOR_LENGHT) << std::setfill('=') << "\n"
    << "|" << std::setw(inter_space + 1) << std::setfill(' ') << RESET
    << msg ;
  if (msg_len % 2 == 1)
    std::cout << " ";
  std::cout
    << std::setw(inter_space + 1) << "|" << "\n"
    << std::setw(SEPARATOR_LENGHT) << std::setfill('=') << "\n";
}

template <typename T>
void printElement(T const & element) {
  std::cout << element << "\n";
}

template <typename T>
void changeToZero(const T & element){
  T& nonConstElement = const_cast<T&>(element);
  nonConstElement = 0;
}

template <>
void changeToZero<std::string>(const std::string & element){
  std::string& nonConstElement = const_cast<std::string&>(element);
  nonConstElement = "";
}

int main( void ) {
  SeparatorMsg("Number Array");
  int numbers[] = {8, 16, 24, 32, 40, 48, 56, 64, 72, 80};
  ::iter(numbers, 10, printElement);
  SeparatorLine();
  ::iter(numbers, 10, changeToZero);
  ::iter(numbers, 10, printElement);

  SeparatorMsg("String Array");
  std::string lotr[] = {
    "Frodo", "Sam", "Gandalf", "Aragorn", "Legolas",
    "Gimli", "Boromir", "Merry", "Pippin"};
  ::iter(lotr, 9, printElement);
  SeparatorLine();
  ::iter(lotr, 9, changeToZero);
  ::iter(lotr, 9, printElement);
}

// Correction Test

// class Awesome
// {
//   public:
//     Awesome( void ) : _n( 42 ) { return; }
//     int get( void ) const { return this->_n; }
//   private:
//     int _n;
// };

// std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
// {
//   o << rhs.get();
//   return o;
// }

// template< typename T >
// void print( T& x )
// {
//   std::cout << x << std::endl;
//   return;
// }

// int main() {
//   int tab[] = { 0, 1, 2, 3, 4 };
//   Awesome tab2[5];

//   iter( tab, 5, print<const int> );
//   iter( tab2, 5, print<Awesome> );

//   return 0;
// }