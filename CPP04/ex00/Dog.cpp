#include "Dog.hpp"

Dog::Dog(): Animal("Dog")
{
	std::cout << "Dog default constructor called." << std::endl;
}

Dog::Dog(std::string type): Animal("Dog")
{
	this->type = type;
	std::cout << "Dog constructor with type " << type << " called." << std::endl;
}

Dog::Dog(const Dog& other)
{
	*this = other;
	std::cout << "Dog copy constructor called." << std::endl;
}

Dog	&Dog::operator=(const Dog& other)
{
	std::cout << "Dog copy assignment operator called." << std::endl;
	if (this != &other)
		this->type = other.type;
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog default destructor called." << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "Woff!" << std::endl;
}

std::string	Dog::getType() const
{
	return this->type;
}


void	Dog::setType(std::string type)
{
	this->type = type;
}
