#pragma once

#include <iostream>
#include <ostream>
#include <string>
#include <cmath>

class Fixed
{
	private:
		int					_nbrValue;
		static const int	_fracBits;
	public:
		Fixed();								// default constructor
		Fixed(const Fixed& other);				// copy constructor
		Fixed &operator=(const Fixed &other);	// copy assignment operator overload
		~Fixed();								// destructor
		Fixed(const int nbr);					// constructor that takes a const int 
		Fixed(const float nbr);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		// Comparison operators
		bool operator>(const Fixed &other) const;
		bool operator<(const Fixed &other) const;
		bool operator>=(const Fixed &other) const;
		bool operator<=(const Fixed &other) const;
		bool operator==(const Fixed &other) const;
		bool operator!=(const Fixed &other) const;

		// Arithmetic operators
		Fixed operator+(const Fixed &other) const;
		Fixed operator-(const Fixed &other) const;
		Fixed operator*(const Fixed &other) const;
		Fixed operator/(const Fixed &other) const;
		
		// Increment/Decrement
		Fixed &operator++();					// pre-increment
		Fixed operator++(int);					// post-increment
		Fixed &operator--();					// pre-decrement
		Fixed operator--(int);					// post-decrement
		
		// Overloaded functions
		static Fixed	&min(Fixed &n1, Fixed &n2);
		static const Fixed	&min(Fixed const &n1, Fixed const &n2);
		static Fixed	&max(Fixed &n1, Fixed &n2);
		static const Fixed 	&max(Fixed const &n1, Fixed const &n2);
};

std::ostream	&operator<<(std::ostream& param, Fixed const& fpr);
