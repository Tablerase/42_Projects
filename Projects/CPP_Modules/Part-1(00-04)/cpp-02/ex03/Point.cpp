/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 12:09:46 by rcutte            #+#    #+#             */
/*   Updated: 2024/04/12 14:35:50 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0){}

Point::Point(const float input_x, const float input_y) : x(input_x), y(input_y){}

Point::Point(const Point &obj) : x(obj.x), y(obj.y){}

Point &Point::operator=(const Point &rhs){ return *this; } // cant reassign const attributes

Point::~Point(){}

Fixed Point::getX() const {
  return this->x;
}

Fixed Point::getY() const {
  return this->y;
}

std::ostream &operator<<(std::ostream &os, const Point &obj){
  os << "x= " << BLU << obj.getX().toFloat() << " " << RESET
    << "y= " << BLU << obj.getY().toFloat() << " " << RESET;
  return os;
}
