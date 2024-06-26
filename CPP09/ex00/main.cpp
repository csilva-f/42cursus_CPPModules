#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		try
		{
			BitcoinExchange	bitcoin;
			bitcoin.getMultipliedRates(argv[1]);
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
			return 1;
		}
	}
	else
		std::cerr << "Error: you must provide an input file.\n";
	return 0;
}
