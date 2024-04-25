#include "Character.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

Character::Character()
{
	for (int i = 0; i < 4; i++)
		this->_inv[i] = 0;
	for (int i = 0; i < 1000; i++)
		this->_uinv[i] = 0;
	std::cout << "Character default constructor called\n";
}

Character::Character(std::string const& name): _name(name)
{
	for (int i = 0; i < 4; i++)
		this->_inv[i] = 0;
	for (int i = 0; i < 1000; i++)
		this->_uinv[i] = 0;
	std::cout << "Character constructor with name " << name << " called\n";
}

Character::Character(const Character& other): ICharacter(other), _inv()
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
			if (this->_inv[i] != 0)
				delete (this->_inv[i]);
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
	/*for (int j = 0; j < 1000; j++)
	{
		if (this->_uinv[j] != 0)
			delete (this->_uinv[j]);
	}*/
}

void	Character::equip(AMateria* m)
{
	int n = 0;
	for (int i = 0; i < 4 && this->_inv[i]; i++)
		n++;
	if (!m)
	{
		std::cout << "It was not possible to equip Character\n";
		return;
	}
	this->_inv[n] = m;
	std::cout << "Character equipped with Materia of type " << m->getType() << "\n";
}

void	Character::unequip(int idx)
{
	int n = 0;
	for (int i = 0; i < 1000 && this->_uinv[i]; i++)
		n++;
	if (n == 999)
	{
		std::cout << "The discarded inventory is full - it is not possible to unequip anymore\n";
		return;
	}
	else if (this->_inv[idx] && idx > -1 && idx < 4)
	{
		this->_uinv[n] = this->_inv[idx];
		this->_inv[idx] = 0;
		std::cout << "Character unequipped in index " << idx << "\n";
		return;
	}
	std::cout << "It was not possible to unequip Character\n";
}

void	Character::use(int idx, ICharacter& target)
{

	if (idx > -1 && idx < 4 && this->_inv[idx] != 0)
	{
		if (this->_inv[idx]->getType() == "ice" || this->_inv[idx]->getType() == "cure")
		{
			this->_inv[idx]->use(target);
			return;
		}
	}
	std::cout << "It was not possible to do anything to " << target.getName() << "\n";
}

std::string const&	Character::getName() const
{
	return this->_name;
}
