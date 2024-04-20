#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main(void)
{
	Base*	base;

	srand(time(0));
	for (int i = 0; i < 5; i++)
	{
		base = generate();
		if (base)
		{
			std::cout << "(" << i + 1 << ") Base generated successfuly\n";
			identify(base);
			identify(*base);
	  	std::cout << std::endl;
		}
		delete base;
	}
	return 0;
}
