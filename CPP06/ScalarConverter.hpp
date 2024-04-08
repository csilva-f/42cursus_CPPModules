#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <limits>

class ScalarConverter
{
private:
	ScalarConverter() {}
public:
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter &operator=(const ScalarConverter& other);
	~ScalarConverter() {}

	static bool		isChar(const std::string &str);
	static bool		isFloatOrDouble(const std::string &str);
	static bool		isPseudo(const std::string &str);
	static void		convert(std::string &str);
};
