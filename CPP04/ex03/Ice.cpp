#include "Ice.hpp"

Ice::Ice(): AMateria("ice")
{
	std::cout << "Ice default constructor called\n";
}

Ice::Ice(const Ice& other): AMateria(other)
{
	std::cout << "Ice copy constructor called\n";
}

Ice	&Ice::operator=(const Ice& other)
{
	if (this != &other)
		this->_type = other.getType();
	std::cout << "Ice copy assignment operator called\n";
	return *this;
}

Ice::~Ice()
{
	std::cout << "Ice destructor called\n";
}

Ice*	Ice::clone() const
{
	return new Ice(*this);
}

void	Ice::use(ICharacter &target) const
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}
