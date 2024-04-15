/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 12:06:29 by rcutte            #+#    #+#             */
/*   Updated: 2024/04/12 14:35:56 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef POINT_H_
# define POINT_H_

#include "Fixed.hpp"

class Point
{
private:
  Fixed const x;
  Fixed const y;

public:
  Point();
  Point(const float input_x, const float input_y);
  Point(const Point &obj);
  Point &operator=(const Point &obj);
  ~Point();

  Fixed getX() const;
  Fixed getY() const;
};

std::ostream &operator<<(std::ostream &os, const Point &obj);

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif