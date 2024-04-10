/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:14:44 by rcutte            #+#    #+#             */
/*   Updated: 2024/04/09 18:18:03 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HARL_H_
#define HARL_H_

#include <iostream>
#include "color.h"

class Harl{
  private:
    void debug( void );
    void info( void );
    void warning( void );
    void error( void );

    static const int amount_of_levels = 4;
    void (Harl::*functionArray[amount_of_levels])() = { 
      &Harl::debug,
      &Harl::info,
      &Harl::warning,
      &Harl::error
    };
    std::string levels[amount_of_levels] = {
      "DEBUG",
      "INFO",
      "WARNING",
      "ERROR"
    };

  public:
    Harl();
    ~Harl();
    
    void complain( std::string level );
};

#endif
