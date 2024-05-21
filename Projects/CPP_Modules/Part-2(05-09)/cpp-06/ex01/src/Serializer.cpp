/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:13:45 by rcutte            #+#    #+#             */
/*   Updated: 2024/05/20 14:55:37 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Serializer.hpp"

/* ======================== Constructor / Destructor ======================== */

Serializer::Serializer(){}
Serializer::Serializer(const Serializer &other){ (void)other; }
Serializer &Serializer::operator=(const Serializer &rhs){
  (void)rhs;
  return *this;
}
Serializer::~Serializer(){}

/* =============================== Functions ================================ */

/**
 * @brief Data pointer convert to uintptr_t
 * @note It takes a pointer and converts it 
 * to the unsigned integer type uintptr_t.
*/
uintptr_t Serializer::serialize(Data* ptr){
  return reinterpret_cast<uintptr_t>(ptr);
}

/**
 * @brief uintptr_t convert to Data pointer
 * @note It takes an unsigned integer parameter and converts it
 * to a pointer to Data.
*/
Data* Serializer::deserialize(uintptr_t raw){
  return reinterpret_cast<Data*>(raw);
}
