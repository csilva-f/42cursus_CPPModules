#include "Point.hpp"

bool bsp(Point const t1, Point const t2, Point const t3, Point const p)
{
	Fixed areaTotal = Point::getArea(t1, t2, t3);
    Fixed at1 = Point::getArea(t1, t2, p);
    Fixed at2 = Point::getArea(t1, t3, p);
    Fixed at3 = Point::getArea(t3, t2, p);
    
	return(areaTotal == (at1 + at2 + at3));
}
