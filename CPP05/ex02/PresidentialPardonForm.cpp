#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5), _target("target")
{
	std::cout << "PresidentialPardonForm default constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm constructor with target " << target << " called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other): AForm(other), _target(other._target)
{
	std::cout << "PresidentialPardonForm copy constructor called." << std::endl;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
		this->_target = other._target;
	std::cout << "PresidentialPardonForm copy assignment operator called." << std::endl;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called." << std::endl;
}

void	PresidentialPardonForm::executeForm() const
{
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
