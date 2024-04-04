#include "Form.hpp"

Form::Form(): _signed(false), _gsign(150), _gexec(150)
{
	std::cout << "Form default constructor called." << std::endl;
}

Form::Form(const std::string name, const int sign, const int exec): _name(name), _signed(false), _gsign(sign), _gexec(exec)
{
	if (sign < 1 || exec < 1)
		throw Form::GradeTooHighException();
	else if (sign > 150 || exec > 150)
		throw Form::GradeTooLowException();
	else
		std::cout << "Form constructor with name " << name << ", " << sign << " as the required grade to sign and " << exec << " as the required grade to execute called." << std::endl;
}

Form::Form(const Form& other): _name(other._name), _signed(other._signed), _gsign(other._gsign), _gexec(other._gexec)
{
	std::cout << "Form copy constructor called." << std::endl;
}

Form	&Form::operator=(const Form& other)
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

std::string	Form::getFormName() const
{
	return this->_name;
}

bool		Form::getFormSign() const
{
	return this->_signed;
}

int			Form::getFormGSign() const
{
	return this->_gsign;
}

int			Form::getFormGExec() const
{
	return this->_gexec;
}

void		Form::beSigned(const Bureaucrat& bureau)
{
	try
	{
		if (bureau.getGrade() > this->getFormGSign())
			throw Bureaucrat::GradeTooLowException();
		else
		{
			this->_signed = true;
			std::cout << bureau.getName() << " signed " << this->getFormName() << "." << std::endl;
		}
	}
	catch (std::exception &e)
	{
		std::cerr << "Error!" << e.what() << std::endl;
	}
}

const char	*Form::GradeTooLowException::what(void) const throw()
{
	return ("Form grade too low!");
}

const char	*Form::GradeTooHighException::what(void) const throw()
{
	return ("Form grade too high!");
}

std::ostream	&operator<<(std::ostream& os, const Form& other)
{
	os << other.getFormName() << ", form with grade to sign " << other.getFormGSign();
	os << " and grade to execute " << other.getFormGExec() << ". Is Signed? ";
	os << other.getFormSign() << std::endl;
	return(os);
}
