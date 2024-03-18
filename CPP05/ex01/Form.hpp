#pragma once

#include "Bureaucrat.hpp"

class Form
{
public:
	Form();
	Form(const std::string name, const ssize_t gradeToSign, const ssize_t gradeToExecute);
	Form(const Form& other);
	Form &operator=(const Form& other);
	~Form();

	std::string	getName() const;
	bool		getSigned() const;
	ssize_t		getGradeSign() const;
	ssize_t		getGradeExecute() const;

	void				beSigned(const Bureaucrat& other);

class GradeTooHighException: public std::exception
{
public:
	virtual const char *what() const throw();
};

class GradeTooLowException: public std::exception
{
public:
	virtual const char *what() const throw();
};

private:
	const std::string	_name;
	bool				_signed;
	const ssize_t		_gradeToSign;
	const ssize_t		_gradeToExecute;

};

std::ostream	&operator<<(std::ostream& os, const Form& other);
