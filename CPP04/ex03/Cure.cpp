#include "Cure.hpp"
#include "AMateria.hpp"

Cure::Cure(): AMateria("cure")
{
	std::cout << "Cure default constructor called\n";
}

Cure::Cure(const Cure& other): AMateria(other)
{
	*this = other;
	std::cout << "Cure copy constructor called\n";
}

Cure	&Cure::operator=(const Cure& other)
{
	if (this != &other)
		this->_type = other.getType();
	std::cout << "Cure copy assignment operator called\n";
	return *this;
}

Cure::~Cure()
{
	std::cout << "Cure destructor called\n";
}

Cure*	Cure::clone() const
{
	return new Cure(*this);
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *\n";
}
