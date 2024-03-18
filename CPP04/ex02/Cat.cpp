#include "Cat.hpp"

Cat::Cat(): Animal("Cat")
{
	this->_brain = new Brain();
	std::cout << "Cat default constructor called." << std::endl;
}

Cat::Cat(std::string type): Animal("Cat")
{
	this->_brain = new Brain();
	std::cout << "Cat constructor with type " << type << " called." << std::endl;
}

Cat::Cat(const Cat& other)
{
	this->_brain = new Brain(*other._brain);
	this->setType(other.getType());
	std::cout << "Cat copy constructor called." << std::endl;
}

Cat	&Cat::operator=(const Cat& other)
{
	std::cout << "Cat copy assignment operator called." << std::endl;
	if (this != &other)
	{
		this->type = other.type;
		delete this->_brain;
		this->_brain = new Brain(*other._brain);
	}
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat default destructor called." << std::endl;
	delete this->_brain;
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

Brain	&Cat::getBrain() const
{
	return *this->_brain;
}
