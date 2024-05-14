/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:00:11 by rcutte            #+#    #+#             */
/*   Updated: 2024/04/09 18:21:50 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Harl.hpp"

int main()
{
  Harl veteran_eater{};

  std::cout 
    << WHTB << "Harl is in the Restaurant" << RESET << "\n";
  veteran_eater.complain("Hello There !");
  
  std::cout 
    << WHTB << "Harl starts Complaining" << RESET << "\n";
  veteran_eater.complain("DEBUG");
  veteran_eater.complain("INFO");
  veteran_eater.complain("WARNING");
  veteran_eater.complain("ERROR");
}
