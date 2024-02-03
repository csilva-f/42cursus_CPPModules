#include "Fixed.hpp"

const int	Fixed::_fracBits = 8;

// Default Constructor 
Fixed::Fixed()
{
	std::cout << "Default constructor called." << std::endl;
	this->_nbrValue = 0;
}

// Destructor
Fixed::~Fixed()
{
	std::cout << "Destructor called." << std::endl;
}

// Copy Constructor
Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called." << std::endl;
	*this = other;
}

// Copy assignment operator
Fixed &Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called." << std::endl;
	if (this != &other)
		this->_nbrValue = other.getRawBits();
	return *this;
}

// Other Constructors
Fixed::Fixed(const int nbr)
{
	std::cout << "Int constructor called." << std::endl;
	this->_nbrValue = nbr * (1 << Fixed::_fracBits);
}

Fixed::Fixed(const float nbr)
{
	std::cout << "Float constructor called." << std::endl;
	this->_nbrValue = roundf(nbr * (1 << Fixed::_fracBits));
}

// Member functions
int	Fixed::getRawBits(void) const
{
	return this->_nbrValue;
}

void	Fixed::setRawBits(int const raw)
{
	this->_nbrValue = raw;
}

float	Fixed::toFloat() const
{
	return ((float)this->_nbrValue / (float)(1 << Fixed::_fracBits));
}

int	Fixed::toInt() const
{
	return (this->_nbrValue >> Fixed::_fracBits);
}

std::ostream	&operator<<(std::ostream& param, Fixed const& fpr)
{
	param << fpr.toFloat();
	return (param);
}
