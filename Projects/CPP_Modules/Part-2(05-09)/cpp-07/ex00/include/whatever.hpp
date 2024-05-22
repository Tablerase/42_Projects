/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:08:18 by rcutte            #+#    #+#             */
/*   Updated: 2024/05/20 18:49:33 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_H_
#define WHATEVER_H_

# include <iostream>

template <typename T>
void swap(T &first, T &second){
  T tmp = first;
  first = second;
  second = tmp;
};

template <typename T>
T min(T const &first, T const &second){
  return (first >= second ? second : first);
}

template <typename T>
T max(T const &first, T const &second){
  return (first <= second ? second : first);
}

#endif