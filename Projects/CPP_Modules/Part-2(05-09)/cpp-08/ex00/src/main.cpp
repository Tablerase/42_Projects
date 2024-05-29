/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:08:20 by rcutte            #+#    #+#             */
/*   Updated: 2024/05/26 12:20:01 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/easyfind.hpp"

#define SEPARATOR_LENGHT 60

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

template<typename T>
void Display(const T &container) {
    for(typename T::const_iterator it = container.begin(); it != container.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void TestEasyFind(const T &container, int const &to_find){
  bool found = false;
  try {
    found = easyfind(container, to_find);
    std::cout
    << "Number: " << BLU << to_find << RESET << " - "
    << GRNB << "FOUND" << RESET
    << " in the container" << std::endl;
  } catch (std::exception &e){
    std::cout
    << "Number: " << BLU << to_find << RESET << " - "
    << REDB << "NOT FOUND" << RESET
    << " in the container" << " because " << e.what() << std::endl;
  }
}

int main( void ) {
  {
    SeparatorMsg("Vector Int Container");
    std::vector<int> test_vector;
    for (int i = 0; i < 5; i++){
      test_vector.push_back(i);
    }
    Display(test_vector);
    
    SeparatorLine();
    
    int test = 4;
    TestEasyFind(test_vector, test);
    
    SeparatorLine();
    test = 5;
    TestEasyFind(test_vector, test);
  }
  {
    SeparatorMsg("List Float Container");
    std::list<float> test_container;
    for (float i = 1; i < 5; i += 0.25){
      test_container.push_back(i);
    }
    Display(test_container);
    
    SeparatorLine();
    
    float test = 4.25;
    TestEasyFind(test_container, test);
    
    SeparatorLine();
    test = 5;
    TestEasyFind(test_container, test);
  }
}