#include "Character.hpp"
#include "AMateria.hpp"

Character::Character()
{
	for (int i = 0; i < 4; i++)
		_inv[i] = NULL;
	for (int i = 0; i < 1000; i++)
		_uinv[i] = NULL;
	std::cout << "Character default constructor called\n";
}

Character::Character(std::string const& name): _name(name)
{
	for (int i = 0; i < 4; i++)
		_inv[i] = NULL;
	for (int i = 0; i < 1000; i++)
		_uinv[i] = NULL;
	std::cout << "Character constructor with name " << name << " called\n";
}

Character::Character(const Character& other)
{
	*this = other;
	std::cout << "Character copy constructor called\n";
}

Character	&Character::operator=(const Character& other)
{
	std::cout << "Character copy assignment operator called\n";
	if (this != &other)
	{
		this->_name = other.getName();
		for (int i = 0; i < 4; i++)
		{
			if (this->_inv[i])
				delete this->_inv[i];
			if (other._inv[i])
	   			this->_inv[i] = other._inv[i]->clone();
		}
	}
	return *this;
}

Character::~Character()
{
	std::cout << "Character destructor called\n";
	for (int i = 0; i < 4; i++)
	{
		if (this->_inv[i])
			delete (this->_inv[i]);
	}
	for (int i = 0; i < 1000; i++)
	{
		if (this->_uinv[i])
			delete (this->_uinv[i]);
	}
}

void	Character::equip(AMateria* materia)
{
	int n = 0;
	for (int i = 0; i < 4 && this->_inv[i]; i++)
		n++;
	if (!materia)
	{
		std::cout << "It was not possible to equip Character\n";
		return;
	}
	this->_inv[n] = materia;
	std::cout << "Character equipped with Materia of type " << materia->getType() << "\n";
}

void	Character::unequip(unsigned int i)
{
	int n = 0;
	for (int j = 0; j < 1000 && this->_uinv[j]; j++)
		n++;
	if (n == 999)
	{
		std::cout << "The discarded inventory is full - it is not possible to unequip anymore\n";
		return;
	}
	else if (this->_inv[i] && i > -1 && i < 4)
	{
		this->_uinv[n] = this->_inv[i];
		this->_inv[i] = NULL;
		std::cout << "Character unequipped in index " << i << "\n";
		return;
	}
	std::cout << "It was not possible to unequip Character\n";
}
