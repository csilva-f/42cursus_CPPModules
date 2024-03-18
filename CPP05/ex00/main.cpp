#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat	bur1;
	Bureaucrat	bur2("Jack", 3);
	Bureaucrat	bur3("Daniels", 300);
	Bureaucrat	bur4("Gordon", -3);

	std::cout << bur1;
	bur1.gradeDecrement();

	std::cout << bur2;
	bur2.gradeIncrement();
	bur2.gradeIncrement();
	bur2.gradeIncrement();

	return 0;
}
