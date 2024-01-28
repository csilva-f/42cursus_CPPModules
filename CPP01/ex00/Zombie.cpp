#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->_name = name;
	std::cout << "Zombie " << this->_name << " created." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << this->_name << " destructed." << std::endl;
}

void	Zombie::announce()
{
	std::cout << this->_name;
	std::cout << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
