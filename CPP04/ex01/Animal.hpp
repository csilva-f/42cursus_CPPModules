#pragma once

#include <iostream>
#include <string>

#include "Brain.hpp"

class Animal{
public:
	Animal();
	Animal(std::string type);
	Animal(const Animal& other);
	Animal &operator=(const Animal& other);
	virtual ~Animal();

	virtual void	makeSound() const;
	std::string		getType() const;
	void			setType(std::string type);
	virtual Brain	&getBrain() const = 0;

protected:
	std::string	type;
};
