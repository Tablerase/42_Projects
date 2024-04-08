/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 20:46:28 by rcutte            #+#    #+#             */
/*   Updated: 2024/04/05 22:58:08 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "color.h"

#include "Contact.hpp"

Contact::Contact() {
};

Contact::Contact(
  std::string input_first_name_,
  std::string input_last_name_,
  std::string input_nick_name_,
  std::string input_phone_num_,
  std::string input_darkest_secret_
  ) :
    first_name_(input_first_name_),
    last_name_(input_last_name_),
    nick_name_(input_nick_name_),
    phone_num_(input_phone_num_),
    darkest_secret_(input_darkest_secret_) {
  // std::cout << BLUB << "Constructor of Contact called" << RESET << "\n";
}

Contact::~Contact( void ) {
  // std::cout << CYNB << "Destructor of Contact called" << RESET << "\n";
}

void Contact::printContact() const {
  std::cout << getFirstName() << getLastName() << " : " << getNickName() << "\n";
}
