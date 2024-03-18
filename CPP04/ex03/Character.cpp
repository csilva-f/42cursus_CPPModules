#include "Character.hpp"

Character::Character(): _inventory(), _floor()
{
	std::cout << "Character default constructor called." << std::endl;
}

Character::Character(std::string name): _name(name), _inventory(), _floor()
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	std::cout << "Character constructor with name " << name << " called." << std::endl;
}

Character::Character(const Character& other): _inventory(), _floor()
{
	*this = other;
	std::cout << "Character copy constructor called." << std::endl;
}

Character	&Character::operator=(const Character &other)
{
	std::cout << "Character copy assignment operator called." << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i])
				delete this->_inventory[i];
			if (other._inventory[i])
				this->_inventory[i] = other._inventory[i]->clone();
			else
				this->_inventory[i] = 0;
		}
	}
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
		if (this->_floor[i])
			delete this->_floor[i];
	}
	std::cout << "Character destructor called." << std::endl;
}

std::string	const	&Character::getName() const
{
	return this->_name;
}

void	Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!this->_inventory[i] && m)
		{
			bool k = 0;
			for (int j = 0; j < 4; j++)
				if (this->_inventory[j] == m)
					k = 1;
			if (k)
				this->_inventory[i] = m->clone();
			else
				this->_inventory[i] = m;
			return;
		}
	}
}

void	Character::unequip(int idx)
{
	if (idx > -1 && idx < 4 && this->_inventory[idx])
	{
		this->_floor[idx] = this->_inventory[idx];
		this->_inventory[idx] = 0;
	}
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx > -1 && idx < 4 && this->_inventory[idx])
		this->_inventory[idx]->use(target);
	else if (idx < 0 || idx > 3)
		std::cout << "Index out of bounds." << std::endl;
	else if (!this->_inventory[idx])
		std::cout << "Materia does not exist in inventory." << std::endl;
}

