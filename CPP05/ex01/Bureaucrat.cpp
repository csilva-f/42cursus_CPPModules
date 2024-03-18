#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("default"), _grade(150)
{
	std::cout << "Bureaucrat default constructor called. Name: " << this->_name << " Grade: " << this->_grade << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, ssize_t grade): _name(name)
{
	this->setGrade(grade);
	std::cout << "Bureaucrat constructor with name " << name << " and grade " << grade << " called." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
	*this = other;
	std::cout << "Bureaucrat copy constructor called." << std::endl;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &other)
{
	std::cout << "Bureaucrat copy assignment operator called." << std::endl;
	if (this != &other)
		this->setGrade(other.getGrade());
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called." << std::endl;
}

std::string const	Bureaucrat::getName() const
{
	return this->_name;
}

ssize_t	Bureaucrat::getGrade() const
{
	return this->_grade;
}

void	Bureaucrat::setGrade(ssize_t grade)
{
	try 
	{
		if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
		else if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
		this->_grade = grade;
		std::cout << "Grade set as " << grade << " for Bureaucrat " << this->_name << " successfully." << std::endl;
	} 
	catch (std::exception & e)
	{
		std::cerr << "An error occurred: " << e.what() << std::endl;
	}
}

void	Bureaucrat::gradeIncrement()
{
	this->setGrade(this->getGrade() - 1);
}

void	Bureaucrat::gradeDecrement()
{
	this->setGrade(this->getGrade() + 1);
}

const char	*Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low!");
}

const char	*Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high!");
}

std::ostream	&operator<<(std::ostream& os, const Bureaucrat& other)
{
	os << other.getName() << ", bureaucrat grade " << other.getGrade() << std::endl;
	return(os);
}
