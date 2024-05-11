#include "BitcoinExchange.hpp"

/*bool isNumber(const std::string& str)
{
    if (str.empty()) return false;

    for (size_t i = 0; i < str.length(); ++i)
	{
		if ((i == 0 && str[i] == '-') || (i >= 0 && isdigit(str[i])) || str[i] == '.')
			continue;
		else
            return false;
    }
    return true;
}*/

int	checkInput(int idx, std::string line)
{
	if (!idx && line.compare("date | value"))
		return 1;
	if (idx)
	{
		if (line.find("-") != 4 || line.find("-", line.find("-") + 1) != 7)
			return 2;
		char	*p;
		long int	y = strtol(line.substr(0, 4).c_str(), &p, 10);
		long int	m = strtol(line.substr(5, 2).c_str(), &p, 10);
		long int	d = strtol(line.substr(8, 2).c_str(), &p, 10);
		if (y < 1 || m < 1 || d < 1 || m > 12)
			return 3;
		if ((m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) && d > 31)
			return 3;
		else if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30)
			return 3;
		if (y % 4 == 0 && m == 2)
		{
			if (y % 100 == 0)
			{
				if (y % 400 == 0 && d > 29)
					return 3;
				else if (d > 28)
					return 3;
			}
			else if (d > 29)
				return 3;
		}
		else if (m == 2 && d > 28)
			return 3;
		if (line.find(" ") != 10 || line.find(" ", line.find(" ") + 1) != 12 || line.find("|") != 11)
			return 4;
		double	n = strtod(line.substr(13, line.length() - 1).c_str(), &p);
		if (n > 1000)
			return 5;
		else if (n <= 0)
			return 6;
	}
	return 0;
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		try
		{
			std::ifstream	file(argv[1]);
			if (!file.is_open())
			{
				std::cerr << "Error: trouble opening the file " << argv[1] << ".\n";
				return 1;
			}
			bool		isEmpty = true;
			std::string	line;
			//std::map<std::string, std::pair<float, float> > myMap;
			BitcoinExchange	btc;
			for (int i = 0; std::getline(file, line); i++)
			{
				isEmpty = false;
				int	c = checkInput(i, line);
				if (c)
				{
					if (c == 1)
						std::cerr << "Error: first line with headers missing.\n";
					else if (c == 2 || c == 3 || c == 4)
						std::cerr << "Error: bad input => " << line << "\n";
					else if (c == 5)
						std::cerr << "Error: too large a number.\n";
					else if (c == 6)
						std::cerr << "Error: not a positive number.\n";
				}
				else if (i)
				{
					/*char	*p;
					float	n = strtof(line.substr(13, line.length() - 1).c_str(), &p);
					myMap[line.substr(0, 10)] = std::make_pair(n, 0);*/
					std::cout << line << std::endl;
				}
			}
			file.close();
			if (isEmpty)
			{
				std::cerr << "Error: empty file.\n";
				return 1;
			}
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	else
		std::cerr << "Error: could not open file.\n";
	return 0;
}
