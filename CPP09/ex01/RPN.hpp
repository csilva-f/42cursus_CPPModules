#pragma once

# include <iostream>
# include <string>
# include <stack>
# include <cmath>
# include <sstream>
# include <cstdlib>

class RPN
{
private:
	std::stack<double>	_nbrs;

public:
	RPN();
	RPN(const RPN& other);
	RPN	&operator=(const RPN& other);
	~RPN();

	double	getTopStackNbr(void) const;
	void	solveRPNExpression(std::string str);

class OutOfRangeException : public std::exception
{
	public:
		virtual const char* what() const throw();
};

class ErrorException : public std::exception
{
	public:
		virtual const char* what() const throw();
};

class InsufficientOperandsException : public std::exception
{
	public:
		virtual const char* what() const throw();
};

class UndefinedResultException : public std::exception
{
	public:
		virtual const char* what() const throw();
};
};
