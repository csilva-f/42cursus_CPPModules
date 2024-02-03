#pragma once

#include <iostream>
#include <string>

class Fixed
{
	private:
		int					_nbrValue;
		static const int	_fracBits;
	public:
		Fixed();								// default constructor
		Fixed(const Fixed& other);				// copy constructor
		Fixed &operator = (const Fixed &other);	// copy assignment operator overload
		~Fixed();								// destructor
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};
