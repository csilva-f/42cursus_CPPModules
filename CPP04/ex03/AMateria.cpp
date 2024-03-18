#include "AMateria.hpp"

AMateria::AMateria(std::string const &type)
{
	this->type=type;
	std::cout << "Constructor AMateria with type " << this->type << " created." << std::endl;
}

AMateria::AMateria(AMateria const &copy)
{
	*this=copy;
	std::cout << "AMateria Copy constructor called" << std::endl;
}

AMateria const &AMateria::operator=(AMateria const &copy)
{
	std::cout << "AMateria Copy assignment operator called" << std::endl;
	this->type = copy.type;
	return (*this);
}

AMateria::~AMateria(void)
{
	std::cout << "AMateria object destroyed" << std::endl;
}

std::string const & AMateria::getType() const
{
	return(this->type);
}
