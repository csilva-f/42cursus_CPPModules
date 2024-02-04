#include "FragTrap.hpp"

int main(void)
{
	FragTrap fragTrap("FT");
	
	fragTrap.attack("Darth Vader");
	fragTrap.takeDamage(10);
	fragTrap.beRepaired(10);
	fragTrap.highFivesGuys();
	
	return 0;
}
