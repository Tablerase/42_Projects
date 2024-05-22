/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:08:18 by rcutte            #+#    #+#             */
/*   Updated: 2024/05/22 16:21:51 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_H_
#define ITER_H_

# include <iostream>
# include <iomanip>
# include "color.h"

template <typename T>
void iter(T* array, size_t array_lenght, void(*f)(T const &)){
  for (size_t i = 0; i < array_lenght; i++){
    f(array[i]);
  }
}

template <typename T>
void iter(T* array, size_t array_lenght, void(*f)(T &)){
  for (size_t i = 0; i < array_lenght; i++){
    f(array[i]);
  }
}

#endif