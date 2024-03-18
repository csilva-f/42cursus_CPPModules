#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog(): Animal("Dog")
{
	this->_brain = new Brain();
	std::cout << "Dog default constructor called." << std::endl;
}

Dog::Dog(std::string type): Animal("Dog")
{
	this->_brain = new Brain();
	this->type = type;
	std::cout << "Dog constructor with type " << type << " called." << std::endl;
}

Dog::Dog(const Dog& other)
{
	this->_brain = new Brain (*other._brain);
	this->setType(other.getType());
	std::cout << "Dog copy constructor called." << std::endl;
}

Dog	&Dog::operator=(const Dog& other)
{
	std::cout << "Dog copy assignment operator called." << std::endl;
	if (this != &other)
	{
		this->type = other.type;
		delete this->_brain;
		this->_brain = new Brain(*this->_brain);
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog default destructor called." << std::endl;
	delete this->_brain;
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

Brain	&Dog::getBrain() const
{
	return *this->_brain;
}
