#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>

#pragma once
class ICharacter;

class AMateria
{
	protected:
		std::string type;

		AMateria(std::string const &type);
		AMateria(AMateria const &copy);
	public:
		virtual ~AMateria(void);

		AMateria const &operator=(AMateria const &copy);

		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target) = 0;
};

#endif
