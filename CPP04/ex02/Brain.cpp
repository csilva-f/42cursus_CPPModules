#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called." << std::endl;
}

Brain::Brain(const Brain& other)
{
	*this = other;
	std::cout << "Brain copy constructor called." << std::endl;
}

Brain	&Brain::operator=(const Brain &other)
{
	std::cout << "Brain copy assignment operator called." << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			this->setIdeas(i, other.getIdeas(i));
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain default destructor called." << std::endl;
}

std::string	Brain::getIdeas(const int i) const
{
	if (i > -1 && i < 100)
		return this->_ideas[i];
	return "No idea in this index.";
}

void	Brain::setIdeas(const int i, const std::string &ideas)
{
	if (i > -1 && i < 100)
		this->_ideas[i] = ideas;
}
