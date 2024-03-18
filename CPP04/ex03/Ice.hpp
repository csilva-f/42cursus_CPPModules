#pragma once

//#include "AMateria.hpp"
#include <iostream>
#include "ICharacter.hpp"

class Ice: public AMateria
{
public:
	Ice();
	Ice(const Ice& other);
	Ice	&operator=(const Ice& other);
	~Ice();

	virtual AMateria	*clone() const;
	void		use(ICharacter& target);
};
