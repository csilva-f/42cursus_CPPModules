#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat default constructor called." << std::endl;
}

WrongCat::WrongCat(std::string type)
{
	this->_type = type;
	std::cout << "WrongCat constructor with type " << type << " called." << std::endl;
}

WrongCat::WrongCat(const WrongCat& other)
{
	*this = other;
	std::cout << "WrongCat copy constructor called." << std::endl;
}

WrongCat	&WrongCat::operator=(const WrongCat &other)
{
	std::cout << "WrongCat copy assignment operator called." << std::endl;
	if (this != &other)
		this->setType(other.getType());
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat default destructor called." << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << "Miaurrr!" << std::endl;
}

std::string	WrongCat::getType() const
{
	return this->_type;
}

void	WrongCat::setType(std::string type)
{
	this->_type = type;
}
