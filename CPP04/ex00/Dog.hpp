#pragma once

#include "Animal.hpp"

class Dog: public Animal
{
public:
	Dog();
	Dog(std::string type);
	Dog(const Dog& other);
	Dog &operator=(const Dog& other);
	~Dog();

	void			makeSound() const;
	std::string		getType() const;
	void			setType(std::string type);
};
