#include "Fixed.hpp"
#include <algorithm>
#include <filesystem>
#include <system_error>
#include <type_traits>

const int	Fixed::_fracBits = 8;

// Default Constructor 
Fixed::Fixed()
{
	this->_nbrValue = 0;
}

// Destructor
Fixed::~Fixed()
{
}

// Copy Constructor
Fixed::Fixed(const Fixed& other)
{
	*this = other;
}

// Copy assignment operator
Fixed &Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		this->_nbrValue = other.getRawBits();
	return *this;
}

// Other Constructors
Fixed::Fixed(const int nbr)
{
	this->_nbrValue = nbr * (1 << Fixed::_fracBits);
}

Fixed::Fixed(const float nbr)
{
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

// Comparison Operators
bool	Fixed::operator>(const Fixed &other) const
{
	return (this->getRawBits() > other.getRawBits());
}

bool	Fixed::operator<(const Fixed &other) const
{
	return (this->getRawBits() < other.getRawBits());
}

bool	Fixed::operator>=(const Fixed &other) const
{
	return (this->getRawBits() >= other.getRawBits());
}

bool	Fixed::operator<=(const Fixed &other) const
{
	return (this->getRawBits() <= other.getRawBits());
}

bool	Fixed::operator==(const Fixed &other) const
{
	return (this->getRawBits() == other.getRawBits());
}

bool	Fixed::operator!=(const Fixed &other) const
{
	return (this->getRawBits() != other.getRawBits());
}

// Arithmetic Operators
Fixed	Fixed::operator+(const Fixed &other) const
{
	return (this->toFloat() + other.toFloat());
}

Fixed	Fixed::operator-(const Fixed &other) const
{
	return (this->toFloat() - other.toFloat());
}

Fixed	Fixed::operator*(const Fixed &other) const
{
	return (this->toFloat() * other.toFloat());
}

Fixed	Fixed::operator/(const Fixed &other) const
{
	return (this->toFloat() / other.toFloat());
}

// Increment/Decrement
Fixed&	Fixed::operator++()
{
	this->_nbrValue++;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed	aux = *this;
	this->_nbrValue++;
	return aux;
}

Fixed&	Fixed::operator--()
{
	this->_nbrValue--;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed	aux = *this;
	this->_nbrValue--;
	return aux;
}

// MIN/MAX functions
Fixed&	Fixed::min(Fixed &n1, Fixed &n2)	
{
	if (n1 > n2)
		return n2;
	return n1;
}

const Fixed&	Fixed::min(const Fixed &n1, const Fixed &n2)
{
	if (n1 > n2)
		return (n2);
	return (n1);	
}

Fixed&	Fixed::max(Fixed &n1, Fixed &n2)	
{
	if (n1 > n2)
		return n1;
	return n2;
}

const Fixed&	Fixed::max(const Fixed &n1, const Fixed &n2)
{
	if (n1 > n2)
		return (n1);
	return (n2);	
}

// Other functions
std::ostream	&operator<<(std::ostream& param, Fixed const& fpr)
{
	param << fpr.toFloat();
	return (param);
}
