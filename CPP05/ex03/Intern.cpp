#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor called." << std::endl;
}

Intern::Intern(const Intern& other)
{
	*this = other;
	std::cout << "Intern copy constructor called." << std::endl;
}

Intern	&Intern::operator=(const Intern& other)
{
	(void)other;
	std::cout << "Inter copy assignment operator called." << std::endl;
	return *this;
}

Intern::~Intern()
{
	std::cout << "Intern destructor called." << std::endl;
}

AForm	*Intern::makeForm(const std::string &name, const std::string &target)
{
	AForm*		(Intern::*fptr[3])(const std::string&) const = {&Intern::makeShrubberyCreationForm, &Intern::makeRobotomyRequestForm, &Intern::makePresidentialPardonForm};
	std::string	formList[3] = {"Shrubbery Creation", "Robotomy Request", "Presidential Pardon"};
	AForm*		form = 0;

	for (int i = 0; i < 3; i++)
	{
		if (formList[i] == name)
		{
			form = (this->*fptr[i])(target);
	  		std::cout << "Intern creates " << name << "." << std::endl;
			return form;
		}
	}
	throw Intern::InvalidFormCreation();
	return form;
}

AForm  *Intern::makeShrubberyCreationForm(const std::string &target) const
{
    return new ShrubberyCreationForm(target);
}

AForm  *Intern::makeRobotomyRequestForm(const std::string &target) const
{
    return new RobotomyRequestForm(target);
}

AForm  *Intern::makePresidentialPardonForm(const std::string &target) const
{
    return new PresidentialPardonForm(target);
}

const char	*Intern::InvalidFormCreation::what(void) const throw()
{
	return ("Invalid form creation.");
}
