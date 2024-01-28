#include <cctype>
#include <iostream>
#include <string>
#include <cstdlib>

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		unsigned char	c;
		for (int i = 1; i < argc; i++)
		{
			for (int j = 0; argv[i][j]; j++)
			{
				c = toupper(argv[i][j]);
				std::cout << c;
			}
			std::cout << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}
