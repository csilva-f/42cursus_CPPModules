#pragma once

#include <iostream>
#include <string>

#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
	private:
		std::string	_target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		PresidentialPardonForm &operator=(const PresidentialPardonForm& other);
		~PresidentialPardonForm();

		void	executeForm() const;
};
