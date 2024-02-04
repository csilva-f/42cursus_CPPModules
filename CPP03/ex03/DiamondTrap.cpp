#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	std::cout << "DiamondTrap default constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name")
{
	std::cout << "DiamondTrap construtor with name " << name << " called." << std::endl;
	this->_name = name;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_enerPoints = ScavTrap::_enerPoints;
	this->_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other): ClapTrap(other), ScavTrap(other), FragTrap(other)
{
	*this = other;
	std::cout << "DiamondTrap copy constructor called." << std::endl;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap& other)
{
	std::cout << "FragTrap assignment operator overload called." << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_enerPoints = other._enerPoints;
		this->_hitPoints = other._hitPoints;
		this->_attackDamage = other._attackDamage;
	}
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called." << std::endl;
}

void	DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name is: " << this->_name << std::endl;
	std::cout << "ClapTrap name is: " << ClapTrap::_name << std::endl;
}
