#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap scavTrap("ST");
	
	scavTrap.attack("Darth Vader");
	scavTrap.takeDamage(10);
	scavTrap.beRepaired(10);
	scavTrap.guardGate();
	
	return 0;
}
