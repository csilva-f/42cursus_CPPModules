#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	: _hitPoints(10), _enerPoints(10), _attackDamage(0)
{
	std::cout << "Default constructor called." << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	: _name(name), _hitPoints(10), _enerPoints(10), _attackDamage(0)
{
	std::cout << "Construtor with name " << name << " called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	*this = other;
	std::cout << "Copy constructor called." << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_enerPoints = other._enerPoints;
		this->_hitPoints = other._hitPoints;
		this->_attackDamage = other._attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called." << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_hitPoints == 0)
		std::cout << "ClapTrap " << this->_name << " is dead, so it cannot attack." << std::endl;
	else if (this->_enerPoints == 0)
		std::cout << "ClapTrap " << this->_name << " has zero hit points, so it cannot attack." << std::endl;
	else 
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage." << std::endl;
		this->_enerPoints--;
		if (this->_enerPoints == 0)
			std::cout << "ClapTrap " << this->_name << " has no more energy points." << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints == 0)
		std::cout << "ClapTrap " << this->_name << " is already dead." << std::endl;
	else
	{
		std::cout << "ClapTrap " << this->_name << " took damage with " << amount << " hit points." << std::endl;
		this->_hitPoints -= amount;
		if (this->_hitPoints == 0)
			std::cout << "ClapTrap " << this->_name << " died." << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints == 0)
		std::cout << "ClapTrap " << this->_name << " cannot be repaired because it has no hit points." << std::endl;
	else if (this->_enerPoints == 0)
		std::cout << "ClapTrap " << this->_name << " cannot be repaired because it has no energy points." << std::endl;
	else
	{
		std::cout << "ClapTrap " << this->_name << " was repaired with " << amount << " hit points." << std::endl;
		this->_enerPoints--;
		this->_hitPoints += amount;
		if (this->_enerPoints == 0)
			std::cout << "ClapTrap " << this->_name << " has no more energy points." << std::endl;
	}
}
