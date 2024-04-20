#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

int	ScalarConverter::checkInput(const std::string &str)
{
	if (str.find('-', 1) != std::string::npos || str.find('+', 1) != std::string::npos)
		return 1;
	else if ((str.find('f') != std::string::npos || str.find('F') != std::string::npos) &&
			(str[str.length() - 1] != 'f' && str[str.length() - 1] != 'F'))
		return 2;
	else if (str.find('.', str.find('.') + 1) != std::string::npos)
		return 3;

	int	f1 = 0;
	int	f2 = 0;
	for (int i = 0; i < (int)str.size(); i++)
	{
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == '-' || str[i] == '+' \
			|| str[i] == '.' || str[i] == 'f' || str[i] == 'F')
			f1 = 1;
		else if (isprint(str[i]) && (str[i] < '0' || str[i] > '9'))
			f2 = 1;
		if (f1 && f2)
			return 4;
	}
	return 0;
}

void	ScalarConverter::convertFloatOrDouble(const std::string &str)
{
	std::istringstream	iss(str);

	iss.str(str);
	char	*p;
	double	n = strtod(str.c_str(), &p);
	if (!iss.fail())
	{
		if (n - static_cast<int>(n) == 0)
		{
			if (isprint(static_cast<char>(n)))
				std::cout << "char: '" << static_cast<char>(n) << "'\n";
			else if (static_cast<int>(n) < 0 || static_cast<int>(n) > 127)
				std::cout << "char: impossible\n";
			else
				std::cout << "char: Non displayable\n";
			if (n > std::numeric_limits<int>::max() || n < std::numeric_limits<int>::min())
				std::cout << "int: impossible\n";
			else
				std::cout << "int: " << static_cast<int>(n) << "\n";
			if (n > std::numeric_limits<float>::max() || n < -std::numeric_limits<float>::max())
				std::cout << "float: impossible\n";
			else
				std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(n) << "f\n";
			if (n > std::numeric_limits<double>::max() || n < -std::numeric_limits<double>::max())
				std::cout << "double: impossible\n";
			else
				std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(n) << "\n";
		}
		else
		{
			if (isprint(static_cast<char>(n)))
				std::cout << "char: '" << static_cast<char>(n) << "'\n";
			else if (static_cast<int>(n) < 0 || static_cast<int>(n) > 127)
				std::cout << "char: impossible\n";
			else
				std::cout << "char: Non displayable\n";
			if (n > std::numeric_limits<int>::max() || n < std::numeric_limits<int>::min())
				std::cout << "int: impossible\n";
			else
				std::cout << "int: " << static_cast<int>(n) << "\n";
			if (n > std::numeric_limits<float>::max() || n < -std::numeric_limits<float>::max())
				std::cout << "float: impossible\n";
			else
				std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(n) << "f\n";
			if (n > std::numeric_limits<double>::max() || n < -std::numeric_limits<double>::max())
				std::cout << "double: impossible\n";
			else
				std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(n) << "\n";
		}
	}
	else
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "double: impossible\n";
		std::cout << "float: impossible\n";
	}
}

void	ScalarConverter::convertInt(const std::string &str)
{
	char	*p;
	double	n = strtod(str.c_str(), &p);
	if (isprint(static_cast<char>(n)) && n > 0)
		std::cout << "char: '" << static_cast<char>(n) << "'\n";
	else if (static_cast<int>(n) < 0 || static_cast<int>(n) > 127)
		std::cout << "char: impossible\n";
	else
		std::cout << "char: Non displayable\n";
	if (n > std::numeric_limits<int>::max() || n < std::numeric_limits<int>::min())
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " << static_cast<int>(n) << "\n";
	if (n > std::numeric_limits<float>::max() || n < -std::numeric_limits<float>::max())
		std::cout << "float: impossible\n";
	else
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(n) << "f\n";
	if (n > std::numeric_limits<double>::max() || n < -std::numeric_limits<double>::max())
		std::cout << "double: impossible\n";
	else
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(n) << "\n";
}

void	ScalarConverter::convertChar(const std::string &str)
{
	if (isprint(static_cast<char>(str[0])))
		std::cout << "char: '" << static_cast<char>(str[0]) << "'\n";
	else
		std::cout << "char: Non displayable\n";
	if (static_cast<int>(str[0]) > std::numeric_limits<int>::max() ||
		static_cast<int>(str[0]) < std::numeric_limits<int>::min())
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " << static_cast<int>(str[0]) << "\n";
	if (str[0] > std::numeric_limits<float>::max() || str[0] < -std::numeric_limits<float>::max())
		std::cout << "float: impossible\n";
	else
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(str[0]) << "f\n";
	if (str[0] > std::numeric_limits<double>::max() || str[0] < -std::numeric_limits<double>::max())
		std::cout << "double: impossible\n";
	else
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(str[0]) << "\n";
}

void	ScalarConverter::convert(const std::string &str)
{
	std::istringstream	iss(str);

	if (isPseudo(str))
	{
		std::cout << "char: impossible" << std::endl;
	        std::cout << "int: impossible" << std::endl;
		if (str == "-inf" || str == "+inf" || str == "nan")
		{
			std::cout << "float: " << str << "f" << std::endl;
            std::cout << "double: " << str << std::endl;
			return ;
		}
		else
		{
			std::cout << "float: " << str << std::endl;
            std::cout << "double: " << str.substr(0, str.size() - 1) << std::endl;
			return ;
		}
	}
	else if (checkInput(str))
		std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
	else if (isNumber(str))
	{
		if (isFloatOrDouble(str))
			return convertFloatOrDouble(str);
		else
			return convertInt(str);
	}
	else if (isChar(str))
		return convertChar(str);
	else
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "double: impossible\n";
		std::cout << "float: impossible\n";
	}
}

bool	ScalarConverter::isChar(const std::string &str)
{
	return (str.length() == 1 && isprint(str[0]));
}

bool	ScalarConverter::isFloatOrDouble(const std::string &str)
{
	return (str.find('.') != std::string::npos || str.find('f') != std::string::npos || str.find('F') != std::string::npos);
}

bool	ScalarConverter::isPseudo(const std::string &str)
{
	return (str == "-inff" || str == "-inf" || str == "+inf" || str == "nan" || str == "+inff");
}

bool	ScalarConverter::isNumber(const std::string &str)
{
	return (((str[0] >= '0' && str[0] <= '9') || ((str[0] == '-' || str[0] == '+') && str[1] &&
	str[1] >= '0' && str[1] <= '9')) && str.find('-', 1) == std::string::npos && str.find('+', 1) == std::string::npos);
}
