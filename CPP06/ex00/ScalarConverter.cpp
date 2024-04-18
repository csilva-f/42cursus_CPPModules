#include "ScalarConverter.hpp"
#include <cstdlib>
#include <sstream>
#include <string>
#define STRING(Value) #Value

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
	if (str.find('-', 1) != std::string::npos)
		return 1;
	else if ((str.find('f') != std::string::npos || str.find('F') != std::string::npos) && (str[str.length() - 1] != 'f' && str[str.length() - 1] != 'F'))
		return 2;
	else if (str.find('.', str.find('.') + 1) != std::string::npos)
		return 3;
	
	int	f1 = 0;
	int	f2 = 0;
	for (int i = 0; i < (int)str.size(); i++)
	{
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == '-' || str[i] == '.' || str[i] == 'f' || str[i] == 'F')
			f1 = 1;
		else if (isprint(str[i]) && (str[i] < '0' || str[i] > '9'))
			f2 = 1;
		if (f1 && f2)
			return 4;
	}
	return 0;
}

void	ScalarConverter::convertFloat(const std::string &str)
{
	std::istringstream	iss(str);
	
	iss.str(str);
	float	f = atof(iss.str().c_str());
	std::cout << "float: ";
	if (!iss.fail())
	{
		if (f - int(f) == 0)
			std::cout << f << ".0f\n";
		else
			std::cout << f << "f\n";
	}
	else
		std::cout << f << "impossible\n";
}

void	ScalarConverter::convertDouble(const std::string &str)
{
	std::istringstream	iss(str);

	iss.str(str);
	double	d = strtod(str, NULL);
	std::cout << "double: ";
	if (iss.fail())
		std::cout << d << std::endl;
	else
		std::cout << "impossible\n";
}
void	ScalarConverter::convert(const std::string &str)
{
	std::istringstream	iss(str);
	//char				c;
	//int				i;

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
	{
		std::cout << "codigo: " << checkInput(str) << "\n";
		std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
	}
	else if (isNumber(str))
	{
		if (isFloatOrDouble(str))
		{
			if (str.find('f') != std::string::npos || str.find('F') != std::string::npos)
				return convertFloat(str);
			else
				return convertDouble(str);
		}
	/*	else
		{

		}*/
	}
	else 
		return ;
	/*iss >> c;
	std::cout << "char: '";
	if (!iss.fail())
	{
		if (isChar(str))
			std::cout << c << "'"<< std::endl;
		else
			std::cout << "not displayable" << std::endl;
	}
	else
		std::cout << "non displayable" << std::endl;

	iss.clear();
	iss.str(str);
	iss >> i;
	std::cout << "int: ";
	if (!iss.fail())
		std::cout << i << std::endl;
	else
		std::cout << "impossible" << std::endl;

	iss.clear();
	iss.str(str);
	// iss >> f;
	std::string aux;
	f = atof(iss.str().c_str());
	// aux = (std::stringstream() << f).str();
	std::cout << "float: ";
	if (!iss.fail())
	{
		if (f - int(f) == 0)
			std::cout << f<< ".0f\n";
		else
			std::cout << f<< "f\n";
	}
	else
		std::cout << "impossible" << std::endl;

	iss.clear();
	iss.str(str);
	iss >> d;
	std::cout << "double: ";
	if (!iss.fail())
		std::cout << d << std::endl;
	else
		std::cout << "impossible" << std::endl;*/
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
	return (((str[0] >= '0' && str[0] <= '9') || (str[0] == '-' && str[1] && str[1] >= '0' && str[1] <= '9')) && str.find('-', 1) == std::string::npos);
}
