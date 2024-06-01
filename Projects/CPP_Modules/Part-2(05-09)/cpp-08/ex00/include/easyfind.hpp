/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:08:18 by rcutte            #+#    #+#             */
/*   Updated: 2024/05/23 18:55:49 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_H_
#define EASYFIND_H_

# include <iostream>
# include <iomanip>
# include <stdexcept>

# include <list>
# include <vector>
# include <deque>
# include <stack>
# include <queue>
# include <algorithm>

# include "color.h"

template <typename T>
bool easyfind(T const &container, int const &to_find){
  if (std::find(container.begin(), container.end(), to_find) != container.end()){
    return true;
  } else {
    throw std::invalid_argument("Integer not found in the container");
    return false;
  }
}

#endif