#pragma once

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
public:
	WrongCat();
	WrongCat(std::string type);
	WrongCat(const WrongCat& other);
	WrongCat &operator=(const WrongCat& other);
	~WrongCat();

	void			makeSound() const;
	std::string		getType() const;
	void			setType(std::string type);

private:
	std::string		_type;
};
