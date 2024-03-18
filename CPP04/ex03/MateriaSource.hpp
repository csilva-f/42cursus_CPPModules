#pragma once

#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
public:
	MateriaSource();
	MateriaSource(const MateriaSource& other);
	MateriaSource &operator=(const MateriaSource& other);
	~MateriaSource();

	void		learnMateria(AMateria* m);
	AMateria	*createMateria(std::string const & type);
	AMateria	*getMateria(int idx) const;

private:
	AMateria	*_materia[4];
};
