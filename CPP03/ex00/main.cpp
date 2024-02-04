#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap clap("ClapTrap");
	ClapTrap clap2("ClapTrap 2");
	
	clap2.takeDamage(10);
	clap.attack("ClapTrap 2");
	clap2.attack("ClapTrap");
	clap2.beRepaired(5);
	clap2.takeDamage(2);
	clap.attack("ClapTrap 2");
	clap2.takeDamage(3);
	clap.attack("ClapTrap 2");
	clap.attack("ClapTrap 2");
	clap.attack("ClapTrap 2");
	clap.attack("ClapTrap 2");
	clap.attack("ClapTrap 2");
	clap.attack("ClapTrap 2");
	clap.attack("ClapTrap 2");
	clap.attack("ClapTrap 2");
	clap.attack("ClapTrap 2");
	clap.attack("ClapTrap 2");
	
	return 0;
}
