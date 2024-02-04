#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "FragTrap default constructor called." << std::endl;
	this->_hitPoints = 100;
	this->_enerPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	std::cout << "FragTrap construtor with name " << name << " called." << std::endl;
	this->_name = name;
	this->_hitPoints = 100;
	this->_enerPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& other): ClapTrap(other)
{
	*this = other;
	std::cout << "FragTrap copy constructor called." << std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap& other)
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

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called." << std::endl;
}

void	FragTrap::attack(const std::string& target)
{
	if (this->_hitPoints == 0)
		std::cout << "FragTrap " << this->_name << " is dead, so it cannot attack." << std::endl;
	else if (this->_enerPoints == 0)
		std::cout << "FragTrap " << this->_name << " has zero hit points, so it cannot attack." << std::endl;
	else 
	{
		std::cout << "FragTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage." << std::endl;
		this->_enerPoints--;
		if (this->_enerPoints == 0)
			std::cout << "FragTrap " << this->_name << " has no more energy points." << std::endl;
	}
}

void	FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << this->_name << " wants to high five!" << std::endl;
}
