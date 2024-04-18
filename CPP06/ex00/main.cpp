#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		int	i = 0;
		std::string const input = argv[1];
		while (input[i])
		{
			if (input[i] < 32 || input[i] > 126)
				return (2 && std::cerr << "Non displayable input" << std::endl);
			i++;
		}
		ScalarConverter::convert(input);
		return 0;
	}
	std::cerr << "Wrong number of arguments.";
	return 2;
}
