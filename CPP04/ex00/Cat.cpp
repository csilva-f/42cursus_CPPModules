#include "Cat.hpp"

Cat::Cat(): Animal("Cat")
{
	std::cout << "Cat default constructor called." << std::endl;
}

Cat::Cat(std::string type): Animal("Cat")
{
	std::cout << "Cat constructor with type " << type << " called." << std::endl;
}

Cat::Cat(const Cat& other)
{
	*this = other;
	std::cout << "Cat copy constructor called." << std::endl;
}

Cat	&Cat::operator=(const Cat& other)
{
	std::cout << "Cat copy assignment operator called." << std::endl;
	if (this != &other)
		this->type = other.type;
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat default destructor called." << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "Miau!" << std::endl;
}

std::string	Cat::getType() const
{
	return this->type;
}

void	Cat::setType(std::string type)
{
	this->type = type;
}
