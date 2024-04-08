/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 21:02:27 by rcutte            #+#    #+#             */
/*   Updated: 2024/04/05 22:50:41 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef _PHONEBOOK_HPP
  #define _PHONEBOOK_HPP

#include <string>
#include <iomanip>

#include "color.h"
#include "Contact.hpp"

#define PHONE_INPUT_PADDING 16
#define COLUMN_HEADER_WIDTH 16

class Phonebook {
  private:
    int contacts_amount_;
    const int contacts_max_amount_ = 8;
    Contact contact_array_[8];
  public:
    Phonebook();
    ~Phonebook();

    void PhoneAdd();

    void PhoneSearch();
    void PhoneGrid();
    void PhoneSelection();
};

#endif