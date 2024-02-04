#include "Point.hpp"

int main(void)
{
	Point t1(0,0);
	Point t2(10,0);
	Point t3(0,5);
	
	Point p1(12,5);
	Point p2(3,2);
	Point p3(1,1);

	std::cout << "Triangulo: (" << t1.getX() << "," << t1.getY() << "), ";
	std::cout << "(" << t2.getX() << "," << t2.getY() << "), ";
	std::cout << "(" << t3.getX() << "," << t3.getY() << ")" << std::endl;

	std::cout << "P1: (" << p1.getX() << "," << p1.getY() << ")" << std::endl;
	std::cout << "P2: (" << p2.getX() << "," << p2.getY() << ")" << std::endl;
	std::cout << "P3: (" << p3.getX() << "," << p3.getY() << ")" << std::endl;

	std::cout << "P1 no triangulo? R: " << bsp(t1, t2, t3, p1) << std::endl;
	std::cout << "P2 no triangulo? R: " << bsp(t1, t2, t3, p2) << std::endl;
	std::cout << "P3 no triangulo? R: " << bsp(t1, t2, t3, p3) << std::endl;

	return 0;
}
