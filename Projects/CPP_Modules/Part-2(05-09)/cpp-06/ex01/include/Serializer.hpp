/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:15:08 by rcutte            #+#    #+#             */
/*   Updated: 2024/05/20 15:07:48 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <stdint.h>
# include <iomanip>
# include "color.h"

struct Data
{
  std::string school_name;
  int         year_of_entry;
};

class Serializer
{
private:
  Serializer();
  Serializer(const Serializer &other);
  Serializer &operator=(const Serializer &rhs);

public:
  ~Serializer();

  static uintptr_t serialize(Data* ptr);
  static Data* deserialize(uintptr_t raw);
};

#endif