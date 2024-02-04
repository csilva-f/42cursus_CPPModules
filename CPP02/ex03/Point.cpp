#include "Point.hpp"

Point::Point() 
	: _x(0), _y(0)
{}

Point::~Point()
{}

Point::Point(const Point& other)
	: _x(other._x), _y(other._y)
{}

Point	&Point::operator=(const Point& other)
{
	if (this != &other)
	{
		(Fixed)this->_x = other.getX();
		(Fixed)this->_y = other.getY();
	}
	return *this;
}

Point::Point(const float& x, const float& y)
	: _x(x), _y(y)
{}

float	Point::getX() const
{
	return (this->_x.toFloat());
}

float	Point::getY() const
{
	return (this->_y.toFloat());
}

Fixed	Point::getArea(const Point &t1, const Point &t2, const Point &t3)
{
	Fixed _area;

	_area = (t1._x * (t2._y - t3._y) + t2._x * (t3._y - t1._y) + t3._x * (t1._y - t2._y)) / 2;
	if (_area < 0)
		_area = Fixed(-_area.toFloat());
    return (_area);
}
