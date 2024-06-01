/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:08:20 by rcutte            #+#    #+#             */
/*   Updated: 2024/05/28 00:28:31 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/MutantStack.hpp"

void SeparatorLine(){
  std::cout
    << BLU
    << " ────────────────────────────────────────────────────────── "
    << RESET << "\n";
}

void SeparatorMsg(std::string const &msg){
  int msg_len = msg.length();
  int inter_space = (63 - msg_len) / 2;
  std::cout
    << "╔" << "══════════════════════════════════════════════════════════"
    << "╗" << "\n"
    << "║" << std::setw(inter_space + 1) << std::setfill(' ') << RESET
    << msg ;
  if (msg_len % 2 == 0)
    std::cout << " ";
  std::cout
    << std::setw(inter_space + 1) << "║" << "\n"
    << "╚" << "══════════════════════════════════════════════════════════"
    << "╝" << "\n";
}
  
int main( void ) {
  {
    SeparatorMsg("MutantStack Int");

    MutantStack<int> mystack;
    for (int i = 0; i < 25; i++){ mystack.push(i); };
    MutantStack<int>::iterator it = mystack.begin();
    MutantStack<int>::iterator it_end = mystack.end();
    for (; it != it_end; ++it){ std::cout << *it << " "; }
    std::cout << std::endl;
    SeparatorLine();

    for (int i = 0; i < 8; i++){ mystack.pop(); }
    it = mystack.begin();
    it_end = mystack.end();
    for (; it != it_end; ++it){ std::cout << *it << " "; }
    std::cout << std::endl;
  }
  {
    SeparatorMsg("MutantStack String");

    MutantStack<std::string> mystack;
    std::string element = "test";
    for (int i = 0; i < 25; i++){
      std::stringstream ss;
      ss << "[" << i << "]";
      std::string new_element = element + ss.str();
      mystack.push(new_element);
    };

    MutantStack<std::string>::iterator it = mystack.begin();
    MutantStack<std::string>::iterator it_end = mystack.end();
    for (; it != it_end; ++it){ std::cout << *it << " "; }
    std::cout << std::endl;
    SeparatorLine();

    for (int i = 0; i < 8; i++){ mystack.pop(); }
    mystack.push("💎TEST💎");
    it = mystack.begin();
    it_end = mystack.end();
    for (; it != it_end; ++it){ std::cout << *it << " "; }
    std::cout << std::endl;
  }

  
}

// -------------------- Subject MutantStack ----------------------- //

// int main()
// {
//   MutantStack<int> mstack;
//   mstack.push(5);
//   mstack.push(17);
//   std::cout << mstack.top() << std::endl;
//   SeparatorLine();
//   mstack.pop();
//   std::cout << mstack.size() << std::endl;
//   SeparatorLine();
//   mstack.push(3);
//   mstack.push(5);
//   mstack.push(737);
//   //[...]
//   mstack.push(0);
//   MutantStack<int>::iterator it = mstack.begin();
//   MutantStack<int>::iterator ite = mstack.end();
//   ++it;
//   --it;
//   while (it != ite)
//   {
//   std::cout << *it << std::endl;
//   ++it;
//   }
//   std::stack<int> s(mstack);
//   return 0;
// }


// Subject std::list

// int main()
// {
//   std::list<int> mstack;
//   mstack.push_back(5);
//   mstack.push_back(17);
//   std::cout << mstack.back() << std::endl; // top (back for list)
//   SeparatorLine();
//   mstack.pop_back();
//   std::cout << mstack.size() << std::endl;
//   SeparatorLine();
//   mstack.push_back(3);
//   mstack.push_back(5);
//   mstack.push_back(737);
//   //[...]
//   mstack.push_back(0);
//   std::list<int>::iterator it = mstack.begin();
//   std::list<int>::iterator ite = mstack.end();
//   ++it;
//   --it;
//   while (it != ite)
//   {
//   std::cout << *it << std::endl;
//   ++it;
//   }
//   std::list<int> s(mstack);  
//   return 0;
// }

// OUTPUT

// 17
// --------------------------------------------------------
// 1
// --------------------------------------------------------
// 5
// 3
// 5
// 737
// 0