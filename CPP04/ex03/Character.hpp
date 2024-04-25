#pragma once

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

	void				equip(AMateria* m);
	void				unequip(int idx);
	void				use(int idx, ICharacter& target);
	std::string const&	getName() const;
};
