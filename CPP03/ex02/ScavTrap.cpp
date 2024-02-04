#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap default constructor called." << std::endl;
	this->_hitPoints = 100;
	this->_enerPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	std::cout << "ScavTrap construtor with name " << name << " called." << std::endl;
	this->_name = name;
	this->_hitPoints = 100;
	this->_enerPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other): ClapTrap(other)
{
	*this = other;
	std::cout << "ScavTrap copy constructor called." << std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "ScavTrap assignment operator overload called." << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_enerPoints = other._enerPoints;
		this->_hitPoints = other._hitPoints;
		this->_attackDamage = other._attackDamage;
	}
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called." << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->_hitPoints == 0)
		std::cout << "ScavTrap " << this->_name << " is dead, so it cannot attack." << std::endl;
	else if (this->_enerPoints == 0)
		std::cout << "ScavTrap " << this->_name << " has zero hit points, so it cannot attack." << std::endl;
	else 
	{
		std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage." << std::endl;
		this->_enerPoints--;
		if (this->_enerPoints == 0)
			std::cout << "ScavTrap " << this->_name << " has no more energy points." << std::endl;
	}
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode." << std::endl;
}
