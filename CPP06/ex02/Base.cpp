#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	generate(void)
{
	int n = std::rand() % 3;
	switch (n)
	{
		case 0:
			return (new A);
		case 1:
			return (new B);
		case 2:
			return (new C);
	}
	return 0;
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "B\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "C\n";
	else
	 	std::cout << "Error: unrecognized data type or NULL\n";
}

void	identify(Base& p)
{
	try
	{
		A&	refA = dynamic_cast<A&>(p);
		std::cout << "refA\n";
		(void)refA;
	}
	catch (std::exception & e)
	{
		try
		{
			B&	refB = dynamic_cast<B&>(p);
			std::cout << "refB\n";
			(void)refB;
		}
		catch (std::exception & e)
		{
			try
			{
				C&	refC = dynamic_cast<C&>(p);
				std::cout << "refC\n";
				(void)refC;
			}
			catch (std::exception & e)
			{
				std::cout << "Error: dynamic casting of references generated an error\n";
			}
		}
	}
}
