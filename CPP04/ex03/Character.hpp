#pragma once

# include <iostream>
# include "ICharacter.hpp"

class Character: public ICharacter
{
private:
	AMateria*	inv[4];
public:
	Character();

};
