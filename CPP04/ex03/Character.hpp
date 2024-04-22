#pragma once

# include <iostream>
# include "ICharacter.hpp"

class Character: public ICharacter
{
private:
	std::string		_name;
	AMateria*		_inv[4];
	AMateria*		_uinv[1000];
public:
	Character();
	Character(std::string const& name);
	Character(const Character& other);
	Character &operator=(const Character& other);
	~Character();

	void	equip(AMateria* materia);
	void	unequip(unsigned int i);
};
