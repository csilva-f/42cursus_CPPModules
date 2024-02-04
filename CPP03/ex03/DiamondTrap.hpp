#pragma once

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap{
public:
	DiamondTrap();
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap& other);
	DiamondTrap &operator=(const DiamondTrap& other);
	~DiamondTrap();

	void	whoAmI();
	using ScavTrap::attack;

private:
	std::string	_name;	
};
