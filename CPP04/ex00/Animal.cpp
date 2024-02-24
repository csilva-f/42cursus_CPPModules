#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal default constructor called." << std::endl;
}

Animal::Animal(std::string type)
{
	this->type = type;
	std::cout << "Animal constructor with type " << type << " called." << std::endl;
}

Animal::Animal(const Animal& other)
{
	*this = other;
	std::cout << "Animal copy constructor called." << std::endl;
}

Animal	&Animal::operator=(const Animal& other)
{
	std::cout << "Animal copy assignment operator called." << std::endl;
	if (this != &other)
		this->setType(other.getType());
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal default destructor called." << std::endl;
}

void	Animal::makeSound() const
{
	std::cout << "Animal default sound!" << std::endl;
}

std::string	Animal::getType() const
{
	return this->type;
}

void	Animal::setType(std::string type)
{
	this->type = type;
}
