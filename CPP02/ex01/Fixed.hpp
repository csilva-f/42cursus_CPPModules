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
};

std::ostream	&operator<<(std::ostream& param, Fixed const& fpr);
