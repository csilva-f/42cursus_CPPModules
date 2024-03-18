#pragma once

#include <exception>
#include <iostream>
#include <string>

class Bureaucrat
{
public:
	Bureaucrat();
	Bureaucrat(const std::string name, ssize_t grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat &operator=(const Bureaucrat& other);
	~Bureaucrat();

	const std::string 	getName() const;
	ssize_t 				getGrade() const;
	void				setGrade(ssize_t grade);
	void				gradeIncrement();
	void				gradeDecrement();

private:
	const std::string	_name;
	ssize_t				_grade;

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
};

std::ostream	&operator<<(std::ostream& os, const Bureaucrat& other);
