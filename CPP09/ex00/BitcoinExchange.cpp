#include "BitcoinExchange.hpp"

static int	checkDate(std::string date)
{
	if (date.find("-") != 4 || date.find("-", date.find("-") + 1) != 7)
		return 2;
	char	*p;
	long int	y = strtol(date.substr(0, 4).c_str(), &p, 10);
	long int	m = strtol(date.substr(5, 2).c_str(), &p, 10);
	long int	d = strtol(date.substr(8, 2).c_str(), &p, 10);
	if (y < 2009 || m < 1 || d < 1 || m > 12)
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
	return 0;
}

static int	checkInput(int idx, std::string line)
{
	if (!idx && line.compare("date | value"))
		return 1;
	if (idx)
	{
		char	*p;
		int		i = checkDate(line.substr(0, line.find(" ")));
		if (i)
			return i;
		if (line.find(" ") != 10 || line.find(" ", line.find(" ") + 1) != 12
			|| line.find("|") != 11)
			return 4;
		double	n = strtod(line.substr(13, line.length() - 1).c_str(), &p);
		if (n > 1000)
			return 5;
		else if (n <= 0)
			return 6;
	}
	return 0;
}

BitcoinExchange::BitcoinExchange()
{
	std::ifstream	data("data.csv");
	if (!data.is_open())
		throw ErrorDataFileException();
	std::string	line;
	bool		isEmpty = true;
	for(int i = 0; std::getline(data, line); i++)
	{
		isEmpty = false;
		if (!i && line.compare("date,exchange_rate"))
			throw ErrorDataFileException();
		std::string	date = line.substr(0, line.find(","));
		char		*p;
		float		er = strtof(line.substr(line.find(",") + 1, line.length() - line.find(",")).c_str(), &p);
		if ((checkDate(date) || (!er && line.substr(line.find(",") + 1, line.length()).compare("0"))) && i)
			throw ErrorDataFileException();
		this->_rates[date] = er;
	}
	if (isEmpty)
		throw ErrorDataFileException();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	*this = other;
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
		this->_rates = other._rates;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void	BitcoinExchange::getMultipliedRates(std::string filename)
{
	std::ifstream	file(filename.c_str());
	if (!file.is_open())
		throw ErrorInputFileException();
	bool		isEmpty = true;
	std::string	line;
	BitcoinExchange	btc;
	for (int i = 0; std::getline(file, line); i++)
	{
		isEmpty = false;
		int	c = checkInput(i, line);
		if (c)
		{
			if (c == 1)
				throw ErrorInputFileException();
			else if (c == 2 || c == 3 || c == 4)
				std::cerr << "Error: bad input => " << line.substr(0, 10) << "\n";
			else if (c == 5)
				std::cerr << "Error: too large a number.\n";
			else if (c == 6)
				std::cerr << "Error: not a positive number.\n";
		}
		else if (i)
		{
			for (std::map<std::string, float>::iterator it = this->_rates.begin(); it != this->_rates.end(); it++)
			{
				int	n = it->first.compare(line.substr(0, line.find(" ")).c_str());
				if (!n)
				{
					char	*p;
					float	n = strtof(line.substr(13, line.length() - 1).c_str(), &p);
					std::cout << line.substr(0, 10) << " => " << line.substr(13, line.length() - 1);
					std::cout << " = " << n * it->second << std::endl;
					break;
				}
				else if (n > 0)
				{
					if (it != this->_rates.begin())
						it--;
									char	*p;
					float	n = strtof(line.substr(13, line.length() - 1).c_str(), &p);
					std::cout << line.substr(0, 10) << " => " << line.substr(13, line.length() - 1);
					std::cout << " = " << n * it->second << std::endl;
					break;
				}
			}
		}
	}
	file.close();
	if (isEmpty)
		throw ErrorInputFileException();
}

const char	*BitcoinExchange::ErrorDataFileException::what() const throw()
{
	return "Error related to data file";
}

const char	*BitcoinExchange::ErrorInputFileException::what() const throw()
{
	return "Error related to input file";
}
