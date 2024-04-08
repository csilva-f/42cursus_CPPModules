#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter& other)
{
	return *this;
}

ScalarConverter::~ScalarConverter() {}

static void	ScalarConverter::convert(std::string str)
{
	std::istringstream	iss(str);
	char				c;
	int					i;
	float				f;
	double				d;

	iss >> c;
	std::cout << "char: "
	if (!iss.fail())
	{
		if (str.length() == 1 && isprint(str[0]))
			std::cout << c << std::endl;
		else
			std::cout << "not displayable" << std::endl;
	}
	else
		std::cout << "non displayable" << std::endl;

	iss.clear();
	iss.str(str);
	iss >> i;
	std::cout << "int: "
	if (!iss.fail())
		std::cout << i << std::endl;
	else
		std::cout << "impossible" << std::endl;

	iss.clear()
	iss.str(str);
	iss >> f;
	std::cout << "float: "
	if (!iss.fail())
		std::cout << f << std::endl;
	else
		std::cout << "impossible" << std::endl;

	iss.clear();
	iss.str(str);
	iss >> d;
	std::cout << "double: "
	if (!iss.fail())
		std::cout << d << std::endl;
	else
		std::cout << "impossible" << std::endl;
}

static bool	ScalarConverter::isChar(const std::string &str)
{
	return (std.length() == 1 && isprint(std[0]));
}

static bool	ScalarConverter::isFloatOrDouble(const std::string &str)
{
	return (std.find('.') != std::string::npos || str.find('f') != std::string::npos || str.find('F') != std::string::npos);
}

static bool	ScalarConverter::isPseudo(const std::string &str)
{
	return (str == "-inff" || str == "-inf" || str == "+inf" || str == "nan" || str == "+inff");
}


