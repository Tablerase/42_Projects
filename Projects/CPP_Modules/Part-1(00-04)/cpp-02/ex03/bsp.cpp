/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 13:52:21 by rcutte            #+#    #+#             */
/*   Updated: 2024/04/13 09:28:50 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/*
Area of a triangle: Area A = [ x1(y2 – y3) + x2(y3 – y1) + x3(y1-y2)]/2

If the point is inside the triangle, the sum of the areas of the three 
triangles formed by the point and the three vertices of the triangle 
will be equal to the area of the triangle.
*/

Fixed const find_triangle_area( Point const a, Point const b, Point const c){
  Fixed area = (a.getX() * (b.getY() - c.getY())
    + b.getX() * (c.getY() - a.getY()) 
    + c.getX() * (a.getY() - b.getY())) / 2;
  
  if (area.toFloat() < 0)
  {
    area.setRawBits(-area.getRawBits());
    return area;
  }
  else
    return area;
}

bool bsp( Point const a, Point const b, Point const c, Point const point){
  Fixed const area = find_triangle_area(a, b, c);

  Fixed const area1 = find_triangle_area(a, b, point);

  Fixed const area2 = find_triangle_area(a, point, c);

  Fixed const area3 = find_triangle_area(point, b, c);

  if (area.toFloat() == area1.toFloat() + area2.toFloat() + area3.toFloat())
    return true;
  else
    return false;
}
