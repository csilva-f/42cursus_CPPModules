#pragma once

#include <iostream>
#include <string>
#include <fstream>

#include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
	private:
		std::string _target;

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();

		void	executeForm() const;
};
