#include "MateriaSource.hpp"

MateriaSource::MateriaSource(): _materia()
{
	std::cout << "Materia Source default constructor." << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& other): _materia()
{
	*this = other;
	std::cout << "MateriaSource copy constructor called." << std::endl;
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &other)
{
	std::cout << "Materia Source copy assignment operator." << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			if (other.getMateria(i))
				this->_materia[i] = other.getMateria(i)->clone();
		}
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	std::cout << "Materia Source destructor called." << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_materia[i] != 0)
			delete this->_materia[i];
	}
}

void	MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!this->_materia[i] && m)
		{
			this->_materia[i] = m;
			return;
		}
	}
}

AMateria	*MateriaSource::createMateria(const std::string &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materia[i] && this->_materia[i]->getType() == type)
			return this->_materia[i]->clone();
	}
	return 0;
}

AMateria	*MateriaSource::getMateria(int idx) const
{
	return this->_materia[idx];
}
