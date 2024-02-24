#pragma once

#include <iostream>
#include <string>

class WrongAnimal
{
public:
	WrongAnimal();
	WrongAnimal(std::string type);
	WrongAnimal(const WrongAnimal& other);
	WrongAnimal &operator=(const WrongAnimal& other);
	~WrongAnimal();

	void			makeSound() const;
	std::string		getType() const;
	void			setType(std::string type);

protected:
	std::string	type;
};
