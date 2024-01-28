#include "Zombie.hpp"

#define NH 5

Zombie*	zombieHorde(int N, std::string name);

int main()
{
	Zombie	*horde = zombieHorde(NH, "Frankenstein");
	for (int i = 0; i < NH; i++)
		horde[i].announce();
	delete [] horde;
}
