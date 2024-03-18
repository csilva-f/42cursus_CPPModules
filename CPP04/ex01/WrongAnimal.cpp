#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal default constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(std::string type)
{
	this->type = type;
	std::cout << "WrongAnimal constructor with type " << type << " called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	*this = other;
	std::cout << "WrongAnimal copy constructor called." << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &other)
{
	std::cout << "WrongAnimal copy assignment operator called." << std::endl;
	if (this != &other)
		this->setType(other.getType());
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal default destructor called." << std::endl;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal default sound." << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return this->type;
}

void	WrongAnimal::setType(std::string type)
{
	this->type = type;
}
