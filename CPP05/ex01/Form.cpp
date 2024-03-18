#include "Form.hpp"

Form::Form(): _name("default"), _signed(0), _gradeToSign(150), _gradeToExecute(150)
{
	std::cout << "Form default constructor called." << std::endl;
}

Form::Form(const std::string name, const ssize_t gradeToSign, const ssize_t gradeToExecute): _name(name), _signed(0), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	std::cout << "Form constructor with name " << name << " called with a Grade to Sign of " << gradeToSign << " and a Grade to Execute of " << gradeToExecute << "." << std::endl;
	try
	{
		if (gradeToSign > 150 || gradeToExecute > 150)
			throw (Form::GradeTooLowException());
		else if (gradeToSign < 1 || gradeToExecute < 1)
			throw (Form::GradeTooHighException());
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
}

Form::Form(const Form& other): _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	std::cout << "Form copy constructor called." << std::endl;
}

Form	&Form::operator=(const Form &other)
{
	std::cout << "Form copy assignment operator called." << std::endl;
	if (this != &other)
		this->_signed = other._signed;
	return *this;
}

Form::~Form()
{
	std::cout << "Form destructor called." << std::endl;
}

std::string	Form::getName() const
{
	return this->_name;
}

bool	Form::getSigned() const
{
	return this->_signed;
}

ssize_t	Form::getGradeSign() const
{
	return this->_gradeToSign;
}

ssize_t	Form::getGradeExecute() const
{
	return this->_gradeToExecute;
}

void	Form::beSigned(const Bureaucrat &other)
{
	try 
	{
		if (other.getGrade() > this->getGradeSign())
			throw (Form::GradeTooLowException());
		else if (this->_signed == true)
			std::cout << other.getName() << " couldn't sign " << this->getName() << " because it was already signed." << std::endl;
		else
		{
			this->_signed = true;
			std::cout << other.getName() << " signed " << this->getName();
		}
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	checkGrade(const ssize_t grade)
{
	try
	{
		if (grade < 1)
			throw Form::GradeTooHighException();
		else if (grade > 150)
			throw Form::GradeTooLowException();
	} 
	catch (std::exception & e)
	{
		std::cerr << "An error occurred: " << e.what() << std::endl;	
	}
}

std::ostream	&operator<<(std::ostream& os, const Form& other)
{
	os << "Form named " << other.getName() << ":\n\tSign Grade:\t" << other.getGradeSign();
	os << "\n\tExecution Grade:\t" << other.getGradeExecute();
	os << "\n\tIs signed:\t" << other.getSigned() << std::endl;
	return (os);
}
