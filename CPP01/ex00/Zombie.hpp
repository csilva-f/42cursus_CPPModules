#pragma once

#include <iostream>
#include <string>

class Zombie {
private:
	std::string	_name;

public:
	void	announce();
	Zombie(std::string name);
	~Zombie();
};
