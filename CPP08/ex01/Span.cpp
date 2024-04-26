#include "Span.hpp"

Span::Span()
{
	std::cout << "Span default constructor called\n";
}

Span::Span(unsigned int n): _n(n)
{
	std::cout << "Span constructor with value " << n << " called\n";
}

Span::Span(const Span& other): _n(other._n)
{
	this->_vec.clear();
	// clear(): used to remove all elements from the vector container
	this->_vec = other._vec;
	std::cout << "Span copy constructor called\n";
}

Span	&Span::operator=(const Span& other)
{
	std::cout << "Span copy assignment operator called\n";
	this->_n = other._n;
	this->_vec = other._vec;
	return *this;
}

Span::~Span()
{
	std::cout << "Span destructor called\n";
}

void	Span::addNumber(int nbr)
{
	if (this->_vec.size() >= _n)
		throw std::runtime_error("the container is full, it is not possible to add any more numbers\n");
	this->_vec.push_back(nbr);
	std::cout << "Number " << nbr << " successfully added to the container\n";
}

void	Span::addNumbers(std::vector<int>::const_iterator a, std::vector<int>::const_iterator b)
{
	unsigned int n = std::distance(a, b);
	if (this->_vec.size() + n > this->_n)
		throw std::runtime_error("the size of the container does not allow to add all the numbers");
	this->_vec.insert(this->_vec.end(), a, b);
	// insert(): receives the position of the iterator in which we want to insert the elements,
	// the input interator first and the input iterator last
}

int		Span::shortestSpan() const
{
	if (this->_vec.size() < 2)
		throw std::runtime_error("it is not possible to find the spans, container too small\n");
	std::vector<int> sortedVec = this->_vec;
	std::sort(sortedVec.begin(), sortedVec.end());
	// std::sort: input from where the sorting begins and input until where the sorting ends
	int	sp = std::numeric_limits<int>::max();
	for (unsigned int i = 1; i < sortedVec.size(); i++)
	{
		int tmp = sortedVec[i] - sortedVec[i - 1];
		if (sp > tmp)
			sp = tmp;
	}
	return sp;
}

int		Span::longestSpan() const
{
	if (this->_vec.size() < 2)
		throw std::exception();
	std::vector<int> sortedVec = this->_vec;
	std::sort(sortedVec.begin(), sortedVec.end());
	int	lp = sortedVec[sortedVec.size() - 1] - sortedVec[0];
	return lp;
}
