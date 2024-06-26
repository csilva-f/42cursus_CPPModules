#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		try
		{
			RPN	exp;

			exp.solveRPNExpression(argv[1]);
			std::cout << exp.getTopStackNbr() << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
			return 1;
		}
	}
	else
		std::cout << "Error: wrong number of arguments\n";
	return 0;
}
