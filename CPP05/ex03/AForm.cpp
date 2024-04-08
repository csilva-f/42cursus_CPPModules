#include "AForm.hpp"

AForm::AForm(): _signed(false), _gsign(150), _gexec(150)
{
	std::cout << "Form default constructor called." << std::endl;
}

AForm::AForm(const std::string name, const int sign, const int exec): _name(name), _signed(false), _gsign(sign), _gexec(exec)
{
	if (sign < 1 || exec < 1)
		throw AForm::GradeTooHighException();
	else if (sign > 150 || exec > 150)
		throw AForm::GradeTooLowException();
	else
		std::cout << "Form constructor with name " << name << ", " << sign << " as the required grade to sign and " << exec << " as the required grade to execute called." << std::endl;
}

AForm::AForm(const AForm& other): _name(other._name), _signed(other._signed), _gsign(other._gsign), _gexec(other._gexec)
{
	std::cout << "Form copy constructor called." << std::endl;
}

AForm	&AForm::operator=(const AForm& other)
{
	std::cout << "Form copy assignment operator called." << std::endl;
	if (this != &other)
		this->_signed = other._signed;
	return *this;
}

AForm::~AForm()
{
	std::cout << "Form destructor called." << std::endl;
}

std::string	AForm::getFormName() const
{
	return this->_name;
}

bool		AForm::getFormSign() const
{
	return this->_signed;
}

int			AForm::getFormGSign() const
{
	return this->_gsign;
}

int			AForm::getFormGExec() const
{
	return this->_gexec;
}

void		AForm::beSigned(const Bureaucrat& bureau)
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

const char	*AForm::GradeTooLowException::what(void) const throw()
{
	return ("Form: grade too low!");
}

const char	*AForm::GradeTooHighException::what(void) const throw()
{
	return ("Form: grade too high!");
}

const char	*AForm::NotSigned::what(void) const throw()
{
	return ("Form: not signed!");
}

std::ostream	&operator<<(std::ostream& os, const AForm& other)
{
	os << other.getFormName() << ", form with grade to sign " << other.getFormGSign();
	os << " and grade to execute " << other.getFormGExec() << ". Is Signed? ";
	os << other.getFormSign() << std::endl;
	return(os);
}

void 		AForm::execute(const Bureaucrat& bureau) const
{
	try
	{
		if (_signed == false)
			throw AForm::NotSigned();
		else if (_gexec < bureau.getGrade())
			throw AForm::GradeTooLowException();
		this->executeForm();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
