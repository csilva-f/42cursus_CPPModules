#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm():AForm("RobotomyRequestForm", 72, 45), _target("target")
{
	std::cout << "RobotomyRequestForm default constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm constructor with target " << target << " called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other): AForm(other), _target(other._target)
{
	std::cout << "RobotomyRequestForm copy constructor called." << std::endl;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
		this->_target = other._target;
	std::cout << "RobotomyRequestForm copy assignment operator called." << std::endl;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called." << std::endl;
}

void	RobotomyRequestForm::executeForm() const
{
	std::cout << "* drilling noises *" << std::endl;
	srand(time(0));
	int	nbr = rand() % 2;
	if (nbr == 0)
		std::cout << this->_target << " has been robotomized successfully." << std::endl;
	else
		std::cout << this->_target << " failed to be robotomized." << std::endl;
}
