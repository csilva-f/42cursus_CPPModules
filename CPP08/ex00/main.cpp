#include "easyfind.hpp"
#include <limits>

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		char	*p;
		double	n = strtod(argv[1], &p);
		if (n > std::numeric_limits<int>::max() || n < std::numeric_limits<int>::min())
		{
			std::cout << "Error: value introduced out of bounds\n";
			return 0;
		}
		std::vector<int> cont;
		// push_back(value): pushes elements into a vector from the back; inserts at the end
		cont.push_back(0);
		cont.push_back(1);
		cont.push_back(1);
    	cont.push_back(2);
		cont.push_back(3);
    	cont.push_back(5);
		cont.push_back(8);
	    cont.push_back(13);
    	cont.push_back(21);
    	cont.push_back(34);
    	cont.push_back(89);
    	cont.push_back(144);
		try
		{
			std::vector<int>::iterator iter = easyfind(cont, (int)n);
			std::cout << "Value " << (int)n << " found in position "
				<< std::distance(cont.begin(), iter) << "\n";
			// distance(iterator first, iterator last): number of elements between 2 iterators
		}
		catch (const std::exception& e)
		{
			std::cerr << "Error: value not found\n";
		}
	}
	else
		std::cout << "Error: wrong number of arguments\n";
	return 0;
}
