#include "Fixed.hpp"

const int	Fixed::_fracBits = 8;

Fixed::Fixed()
{
	std::cout << "Default constructor called." << std::endl;
	this->_nbrValue = 0;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called." << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called." << std::endl;
	 *this = other;
}

Fixed &Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called." << std::endl;
	if (this != &other)
		this->_nbrValue = other.getRawBits();
	return *this;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called." << std::endl;
	return this->_nbrValue;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called." << std::endl;
	this->_nbrValue = raw;
}
