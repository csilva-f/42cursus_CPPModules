#pragma once

# include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
public:
	MateriaSource();
	MateriaSource(const MateriaSource& other);
	MateriaSource	&operator=(const MateriaSource& other);
	~MateriaSource();
};
