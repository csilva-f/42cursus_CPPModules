#pragma once

#include <iostream>
#include <string>
#include "Fixed.hpp"

class Point {
public:
	Point();
	Point(const Point& other);
	Point &operator=(const Point& other);
	Point(const float& x, const float& y);
	~Point();
	float			getX() const;
	float			getY() const;
	static Fixed	getArea(const Point &t1, const Point &t2, const Point &t3);

private:
	Fixed const	_x;
	Fixed const	_y;
};

bool	bsp(Point const t1, Point const t2, Point const t3, Point const p);
