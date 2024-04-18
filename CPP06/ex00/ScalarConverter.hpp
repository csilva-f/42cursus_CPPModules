#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <cstdlib>

class ScalarConverter
{
private:
	ScalarConverter();
public:
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter &operator=(const ScalarConverter& other);
	~ScalarConverter();

	static bool		isChar(const std::string &str);
	static bool		isPseudo(const std::string &str);
	static void		convert(const std::string &str);
	static bool		isFloatOrDouble(const std::string &str);	
	static bool		isNumber(const std::string &str);
	static int		checkInput(const std::string &str);
	static void		convertFloat(const std::string &str);
	static void		convertDouble(const std::string &str);
};
