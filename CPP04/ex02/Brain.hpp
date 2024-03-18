#pragma once

#include <iostream>
#include <string>

class Brain
{
public:
	Brain();
	Brain(const Brain& other);
	Brain &operator=(const Brain& other);
	~Brain();

	std::string	getIdeas(const int i) const;
	void		setIdeas(const int i, const std::string &ideas);

private:
	std::string	_ideas[100];
};
