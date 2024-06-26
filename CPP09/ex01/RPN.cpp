#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& other): _nbrs(other._nbrs) {}

RPN	&RPN::operator=(const RPN& other)
{
	if (this != &other)
		this->_nbrs = other._nbrs;
	return *this;
}

RPN::~RPN() {}

static bool isNumber(std::string& str)
{
    if (str.empty())
		return false;
    for (size_t i = 0; i < str.length(); ++i)
	{
		if ((i == 0 && str[i] == '-') || (i >= 0 && isdigit(str[i])) || (i == 0 && str[i] == '+'))
			continue;
		else
            return false;
    }
    return true;
}

static double	performCalculation(std::string& tk, int n1, int n2)
{
	return ((tk == "+") ? n1 + n2 : ((tk == "-") ? n1 - n2 : ((tk == "*") ? n1 * n2 : n1 / n2)));
}

double	RPN::getTopStackNbr(void) const
{
	return (this->_nbrs.top());
}

/*void printStack(std::stack<double>& s)
{
    std::stack<double> tempStack = s;

    while (!tempStack.empty())
	{
        std::cout << tempStack.top() << " ";
        tempStack.pop();
    }
    while (!tempStack.empty())
	{
        s.push(tempStack.top());
        tempStack.pop();
    }
    std::cout << std::endl;
}*/

void	RPN::solveRPNExpression(std::string str)
{

	std::istringstream	iss(str);
	std::string			token;

	while (iss >> token)
	{
		if ((token == "+" || token == "-" || token == "/" || token == "*"))
		{
			if (this->_nbrs.size() > 1)
			{
				int	n2 = this->_nbrs.top();
				this->_nbrs.pop();
				int	n1 = this->_nbrs.top();
				this->_nbrs.pop();
				if (token == "/" && n2 == 0)
					throw UndefinedResultException();
				double	res = performCalculation(token, n1, n2);
				this->_nbrs.push(res);
			}
			else
				continue;
		}
		else if (isNumber(token) == true)
		{
			int	n = atoi(token.c_str());
			if (n > 9)
				throw OutOfRangeException();
			this->_nbrs.push(n);
		}
		else
			throw ErrorException();
	}
}

const char	*RPN::OutOfRangeException::what() const throw()
{
	return "Error: input number is greater that 9";
}

const char	*RPN::ErrorException::what() const throw()
{
	return "Error";
}

const char	*RPN::InsufficientOperandsException::what() const throw()
{
	return "Error: insufficient operands";
}

const char	*RPN::UndefinedResultException::what() const throw()
{
	return "Error: undefined operation result";
}
