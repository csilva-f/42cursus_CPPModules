#include "AMateria.hpp"

AMateria::AMateria(): _type("default")
{
	std::cout << "AMateria default constructor called\n";
}

AMateria::AMateria(std::string const &type): _type(type)
{
	std::cout << "AMateria constructor with type " << type << " called.\n";
}

AMateria::AMateria(const AMateria& other): _type(other._type)
{
	std::cout << "AMateria copy constructor called.\n";
}

AMateria &AMateria::operator=(const AMateria& other)
{
	if (this != &other)
		this->_type = other.getType();
	std::cout << "AMateria copy assignment operator called\n";
	return *this;
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor called\n";
}

std::string const	&AMateria::getType() const
{
	return (this->_type);
}

void	AMateria::use(ICharacter& target)
{
	std::cout << "* does nothing to " << target.getName() << " *\n";
}
