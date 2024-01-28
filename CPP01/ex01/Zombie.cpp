#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "Zombie created." << std::endl;
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

void	Zombie::setZombieName(std::string name)
{
	this->_name = name;
}
