#pragma once

#include <iostream>
#include <string>

class Zombie {
private:
	std::string	_name;

public:
	void	announce();
	Zombie();
	~Zombie();
	void	setZombieName(std::string name);
};
