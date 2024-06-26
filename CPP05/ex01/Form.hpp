#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gsign;
		const int			_gexec;

	public:
		Form();
		Form(const std::string name, const int sign, const int exec);
		Form(const Form& other);
		Form &operator=(const Form& other);
		~Form();

		std::string	getFormName() const;
		bool		getFormSign() const;
		int			getFormGSign() const;
		int			getFormGExec() const;

		void		beSigned(const Bureaucrat& bureau);

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

std::ostream	&operator<<(std::ostream& os, const Form& other);
