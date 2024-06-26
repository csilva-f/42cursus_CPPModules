#pragma once

# include <iostream>
# include <string>
# include "ICharacter.hpp"

class AMateria
{
protected:
	std::string		_type;
public:
	AMateria();
	AMateria(std::string const & type);
	AMateria(const AMateria& other);
	AMateria &operator=(const AMateria& other);
	virtual ~AMateria();

	std::string const & getType() const;

	virtual AMateria*	clone() const = 0; // Pure virtual function
	virtual void		use(ICharacter& target);
};
