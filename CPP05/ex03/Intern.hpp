#pragma once

#include <iostream>
#include <string>

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;

class Intern
{
public:
	Intern();
	Intern(const Intern& other);
	Intern &operator=(const Intern& other);
	~Intern();

	AForm	*makeForm(const std::string &name, const std::string &target);
	AForm	*makeShrubberyCreationForm(const std::string &target) const;
	AForm	*makeRobotomyRequestForm(const std::string &target) const;
	AForm	*makePresidentialPardonForm(const std::string &target) const;

	class	InvalidFormCreation: public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};
