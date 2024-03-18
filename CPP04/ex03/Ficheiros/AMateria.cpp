#include "AMateria.hpp"

AMateria::AMateria()
{
	std::cout << "AMateria default constructor called." << std::endl;
}

AMateria::AMateria(std::string const & type) :
	_type(type)
{
	std::cout << "AMateria constructor with type " << type << " called." << std::endl;
}

AMateria::AMateria(const AMateria& other)
{
	*this = other;
	std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria	&AMateria::operator=(const AMateria &other)
{
	std::cout << "AMateria copy assignment operator called." << std::endl;
	if (this != &other)
		this->_type = other.getType();
	//this->_type = other._type;
	return *this;
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor called." << std::endl;
}

std::string const	&AMateria::getType() const
{
	return this->_type;
}

void	AMateria::use(ICharacter &target)
{
	std::cout << "* IMateria use function with target " << target.getName() << " *" << std::endl;
}
