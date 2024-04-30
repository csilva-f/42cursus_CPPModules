#include "PmergeMe.hpp"

bool isNumber(const std::string& str)
{
    if (str.empty()) return false;

    for (size_t i = 0; i < str.length(); ++i)
	{
		if ((i == 0 && str[i] == '-') || (i >= 0 && isdigit(str[i])) || (i == 0 && str[i] == '+'))
			continue;
		else
            return false;
    }
    return true;
}

int	checkInput(char *argv, std::vector<int> i_numbers)
{
	char	*p;
	double	n = strtod(argv, &p);

	if (n > std::numeric_limits<int>::max() || n < std::numeric_limits<int>::min())
	{
		std::cout << "Error: one or more values introduced are out of bounds\n";
		return -1;
	}
	if (n == 0 && isNumber(argv) == false)
	{
		std::cout << "Error: one or more values introduced are not numbers\n";
		return -1;
	}
	if (n < 1 || isNumber(argv) == false)
	{
	   	std::cout << "Error: one or more values introduced are not positive integers\n";
		return -1;
	}
	for (std::vector<int>::iterator it = i_numbers.begin(); it != i_numbers.end(); ++it)
	{
		if (*it == n)
		{
			std::cout << "Error: one or more values introduced are duplicated\n";
			return -1;
		}
    }
	return n;
}

int main(int argc, char **argv)
{
	if (argc > 1)
	{
		std::vector<int> i_numbers;
		for (int i = 1; i < argc; i++)
		{
			if (checkInput(argv[i], i_numbers) > 0)
				i_numbers.push_back(checkInput(argv[i], i_numbers));
		}
		std::cout << "Before:";
		for (int i = 1; i < argc; i++)
			std::cout << " " << argv[i];
		std::cout << "\n-------------------------------\n";
		PmergeMe	pm(i_numbers);
		pm.pmergeMeVector();
		std::cout << "\n-------------------------------\n";
		pm.pmergeMeList();
		/*std::cout << "Vector\n";
		pm.printContainer(pm._vec);
		std::cout << "List\n";
		pm.printContainer(pm._list);*/
	}
	else
	{
		std::cout << "Error: you must specify a collection of numbers to start the algorithm\n";
		return 2;
	}
	return 0;
}
