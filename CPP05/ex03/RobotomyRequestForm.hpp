#pragma once

#include <iostream>
#include <string>
#include <cstdlib>

#include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
	private:
		std::string		_target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm &operator=(const RobotomyRequestForm& other);
		~RobotomyRequestForm();

		void	executeForm() const;
};
