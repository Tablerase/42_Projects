/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:30:51 by rcutte            #+#    #+#             */
/*   Updated: 2024/07/01 13:36:25 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_H_
# define PMERGEME_H_

# include <iostream>
# include <sstream>
# include <iomanip>
# include <exception>
# include <string>
# include <cstdlib>
# include <limits>

# include <algorithm>
# include <cmath>
# include <sys/time.h>
# include <utility>
# include <vector>
# include <deque>

# include "color.h"

// Ford Johnson is inefficient for loads of compare
#define MAX_AUTHORIZED_INPUTS 10000 

class PmergeMe
{
private:
  // Containers

  std::vector<int> origin_array_;
  std::vector<int> vector_array_;
  std::deque<int> deque_array_;

  // Times

  long vector_init_;
  long vector_sort_;
  long deque_init_;
  long deque_sort_;

public:
  /* ______________________________ Constructor _____________________________ */
  PmergeMe();
  PmergeMe(const PmergeMe &other);

  /* ______________________________ Destructor ______________________________ */
  ~PmergeMe();

  /* _______________________________ Operator _______________________________ */
  PmergeMe &operator=(const PmergeMe &other);

  /* ________________________________ Getter ________________________________ */

  std::vector<int> get_vector() const;
  std::deque<int> get_deque() const;
  std::vector<int> get_origin() const;
  long get_vector_time() const;
  long get_deque_time() const;

  /* ________________________________ Setter ________________________________ */

  void set_origin(std::vector<int> input);
  void set_vector(std::vector<int> input);
  void set_deque(std::deque<int> input);
  
  void set_time_vector_init(long time);
  void set_time_vector_sort(long time);
  void set_time_deque_init(long time);
  void set_time_deque_sort(long time);

  /* ____________________________ Member Function ___________________________ */

  void SortVector();
  void SortDeque();

  /* ____________________________ Static Function ___________________________ */

  static bool isSorted(const std::vector<int>& vec);
  static bool isSorted(const std::deque<int>& deq);
  
  /* _______________________________ Exception ______________________________ */
  class Uninitialized_array : public std::exception {
    public:
      const char* what() const throw();
  };

  class Unsorted : public std::exception {
    public:
      const char* what() const throw();
  };
};

  /* ________________________________ Ouput _________________________________ */

std::ostream &operator<<(std::ostream &os, const PmergeMe &obj);

/* --------------------------------- Other ---------------------------------- */

#endif