#pragma once

#include <iostream>
#include <string>

class ClapTrap {
public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap& other);
	ClapTrap &operator=(const ClapTrap& other);
	~ClapTrap();

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

protected: // protected - allows ScavTrap to inherit ClapTrap attribute;
	std::string	_name;
	int			_hitPoints;
	int			_enerPoints;
	int			_attackDamage;
};
