#pragma once

#include "Animal.hpp"
#include <string>

class Cat: public Animal
{
public:
	Cat();
	Cat(std::string type);
	Cat(const Cat& other);
	Cat &operator=(const Cat& other);
	~Cat();

	void			makeSound() const;
	std::string		getType() const;
	void			setType(std::string type);
};
