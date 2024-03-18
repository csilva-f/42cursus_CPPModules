#include "Cure.hpp"

Cure::Cure(): AMateria("cure")
{
	std::cout << "Cure default constructor called." << std::endl;
}

Cure::Cure(const Cure& other) : AMateria("cure")
{
	*this = other;
	std::cout << "Cure copy constructor called." << std::endl;
}

Cure	&Cure::operator=(const Cure& other)
{
	std::cout << "Cure copy assignment operator called." << std::endl;
	//if (this != &other)
	//	this->_type = other.getType();
	(void)other;
	return *this;
}

Cure::~Cure()
{
	std::cout << "Cure destructor called." << std::endl;
}

AMateria	*Cure::clone() const
{
	return new Cure(*this);
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
