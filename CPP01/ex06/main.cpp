#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		Harl	harl;
		int		i;

		std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
		for (i = 0; i < 4; i++)
			if (argv[1] == levels[i])
				break;

		switch (i) {
			case 0:
				harl.complain("DEBUG");
			case 1:
				harl.complain("INFO");
			case 2:
				harl.complain("WARNING");
			case 3:
				harl.complain("ERROR");
				break;
			default:
				std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		}
	}
	else {
		std::cout << "Please specify a level." << std::endl;
	}
	return 0;
}
