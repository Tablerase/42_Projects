/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:08:18 by rcutte            #+#    #+#             */
/*   Updated: 2024/05/28 00:29:46 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_H_
#define MUTANTSTACK_H_

# include <iostream>
# include <sstream>
# include <iomanip>
# include <stdexcept>

# include <deque>
# include <stack>

# include <list>
# include <vector>
# include <queue>
# include <algorithm>
# include "color.h"

// https://en.cppreference.com/w/cpp/header/stack

template <typename T>
class MutantStack : public std::stack<T, std::deque<T> >
{
public:
  /**
   * iterator from base class deque(container_type) -> inherited by stack
   * ==> typedef here for simplicity of usage instead of having a very long name
  */
  typedef typename std::stack<T>::container_type::iterator iterator;

  /**
   * c is the container in stack class template 
   * (here type deque so it has an iterator)
  */
  iterator begin(){ return this->c.begin(); }
  iterator end(){ return this->c.end(); }
};

#endif