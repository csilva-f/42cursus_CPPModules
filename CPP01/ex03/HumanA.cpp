#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) 
	:_name(name), _weapon(weapon)
{
	std::cout << "HumanA " << name;
	std::cout << " generated with a ";
	std::cout << weapon.getType();
	std::cout << " weapon." << std::endl;
}

HumanA::~HumanA()
{
	std::cout << "HumanA " << this->_name;
	std::cout << " destroyed with a ";
	std::cout << this->_weapon.getType();
	std::cout << " weapon." << std::endl;
}

void	HumanA::attack()
{
	std::cout << this->_name;
	std::cout << " attacks with their ";
	std::cout << this->_weapon.getType() << std::endl;
}
