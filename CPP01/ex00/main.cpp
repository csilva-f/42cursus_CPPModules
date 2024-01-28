#include "Zombie.hpp"

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

int main()
{
	Zombie	*hzombie = newZombie("Frankenstein_h");
	hzombie->announce();
	randomChump("Frankenstein_s");
	delete hzombie;
}
