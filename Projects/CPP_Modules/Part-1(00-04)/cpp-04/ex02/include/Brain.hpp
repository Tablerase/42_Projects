/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:27:28 by rcutte            #+#    #+#             */
/*   Updated: 2024/04/17 23:46:34 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H_
# define BRAIN_H_

#include <iostream>
#include "../include/color.h"

class Brain {
  private:
    int amount_of_ideas;
    std::string *ideas;

  public:
    Brain();
    virtual ~Brain();
    Brain(const Brain &obj);
    Brain &operator=(const Brain &rhs);
};

#endif