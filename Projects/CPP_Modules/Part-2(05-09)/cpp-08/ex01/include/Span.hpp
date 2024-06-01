/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:08:18 by rcutte            #+#    #+#             */
/*   Updated: 2024/05/26 17:06:53 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_H_
#define SPAN_H_

# include <iostream>
# include <iomanip>
# include <stdexcept>

# include <list>
# include <vector>
# include <deque>
# include <stack>
# include <queue>
# include <algorithm>
# include <limits>
# include <ctime>
# include <cstdlib>
# include "color.h"

class Span
{
public:
  Span();
  Span(unsigned int const N);
  Span(Span const &other);
  ~Span();

  // Operator

  Span &operator=(Span const &rhs);

  // Getter

  std::list<int> get_list(void) const;
  unsigned int get_max_entity(void) const;

  // Functions

  void addNumber(int const &value);
  void addNumbers(int const &amount_of_elements, int const &value);
  void addNumbers(int const &start_value,
    int const &end_value,
    int const &increment);
  
  unsigned int shortestSpan(void) const;
  unsigned int longestSpan(void) const; 
  
  // Exception

  class SpanIsFull : public std::exception {
    public:
      const char* what() const throw() ;
  };

  class SpanTooSmall : public std::exception {
  public:
    const char* what() const throw();
  };

private:
  std::list<int>  list_;
  unsigned int    max_entity_;

};

std::ostream &operator<<(std::ostream &os, Span const &obj);

void SeparatorLine();
void SeparatorMsg(std::string const &msg);

#endif