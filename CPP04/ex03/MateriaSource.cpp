#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		_inv[i] = NULL;
	std::cout << "MateriaSource default constructor called\n";
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	for (int i = 0; i < 4; i++)
		_inv[i] = NULL;
	*this = other;
	std::cout << "MateriaSource copy constructor called\n";
}

MateriaSource	&MateriaSource::operator=(const MateriaSource& other)
{
	std::cout << "MateriaSource copy assignment operator called\n";
	if (this != &other)
	{
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

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inv[i])
			delete (this->_inv[i]);
	}
	std::cout << "MateriaSource destructor called\n";
}

void	MateriaSource::learnMateria(AMateria* materia)
{
	int n = 0;
	for (int i = 0; i < 4 && this->_inv[i]; i++)
		n++;
	if (!materia)
	{
		std::cout << "It was not possible to learn the Materia, as it does not exist\n";
		return;
	}
	if (n >= 4)
	{
		std::cout << "MateriaSource inventory is full, cannot learn more Materias.\n";
		return;
	}
	this->_inv[n] = materia;
	std::cout << "MateriaSource learned Materia of type " << materia->getType() << "\n";
}

AMateria*	MateriaSource::createMateria(std::string const& type)
{
	for (int i = 0; i < 4 && this->_inv[i]; i++)
	{
		if (this->_inv[i]->getType() == type)
		{
			std::cout << "Materia created based on MateriaSource inventory\n";
			return this->_inv[i]->clone();
		}
	}
	std::cout << "Unknown materia type: " << type << "\n";
	return 0;
}
