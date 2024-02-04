#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap diamondTrap("DT");
	
	diamondTrap.attack("Darth Vader");
	diamondTrap.takeDamage(10);
	diamondTrap.beRepaired(10);
	diamondTrap.highFivesGuys();
	diamondTrap.whoAmI();
	diamondTrap.takeDamage(100);
	diamondTrap.attack("Darth Vader");

	return 0;
}
