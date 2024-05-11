#include "BitcoinExchange.hpp"

int	checkDate(std::string date)
{
	if (date.find("-") != 4 || date.find("-", date.find("-") + 1) != 7)
		return 1;
	char	*p;
	long int	y = strtol(date.substr(0, 4).c_str(), &p, 10);
	long int	m = strtol(date.substr(5, 2).c_str(), &p, 10);
	long int	d = strtol(date.substr(8, 2).c_str(), &p, 10);
	if (y < 1 || m < 1 || d < 1 || m > 12)
		return 1;
	if ((m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) && d > 31)
		return 1;
	else if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30)
		return 1;
	if (y % 4 == 0 && m == 2)
	{
		if (y % 100 == 0)
		{
			if (y % 400 == 0 && d > 29)
				return 1;
			else if (d > 28)
				return 1;
		}
		else if (d > 29)
			return 1;
	}
	else if (m == 2 && d > 28)
		return 1;
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
		//std::cout << "date: " << date << " rate: " << er << "\n";
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

const char	*BitcoinExchange::ErrorDataFileException::what() const throw()
{
	return "Error related to data file";
}
