#include "HumanB.hpp"

HumanB::HumanB(std::string name)
	:_name(name), _weapon(NULL)
{
	std::cout << "HumanB " << name;
	std::cout << " generated without a weapon." << std::endl;
}

HumanB::~HumanB()
{
	std::cout << "HumanB " << this->_name << " destroyed";
	if (this->_weapon == NULL)
		std::cout << " without a weapon." << std::endl;
	else
	{
		std::cout << " with a ";
		std::cout << this->_weapon->getType();
		std::cout << " weapon." << std::endl;
	}
}

void	HumanB::attack()
{
	if (this->_weapon == NULL)
		std::cout<<this->_name << " attacks withouth weapon." << std::endl;
	else
	{
		std::cout <<this->_name << " attacks with their ";
		std::cout << this->_weapon->getType() << std::endl;
	}
}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->_weapon = &weapon;
	std::cout << "Weapon " << (&weapon)->getType();
	std::cout << " set for HumanB ";
	std::cout << this->_name << "." << std::endl;
}
