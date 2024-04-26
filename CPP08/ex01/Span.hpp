#pragma once

# include <iostream>
# include <vector>
# include <algorithm>
# include <iterator>
# include <limits>
# include <stdexcept>

class Span
{
private:
	unsigned int		_n;
	std::vector<int>	_vec;

public:
	Span();
	Span(unsigned int n);
	Span(const Span& other);
	Span &operator=(const Span& other);
	~Span();

	void	addNumber(int nbr);
	void	addNumbers(std::vector<int>::const_iterator a, std::vector<int>::const_iterator b);
	int		shortestSpan() const;
	int		longestSpan() const;
};
