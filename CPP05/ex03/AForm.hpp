#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gsign;
		const int			_gexec;

	public:
		AForm();
		AForm(const std::string name, const int sign, const int exec);
		AForm(const AForm& other);
		AForm &operator=(const AForm& other);
		virtual ~AForm();

		std::string	getFormName() const;
		bool		getFormSign() const;
		int			getFormGSign() const;
		int			getFormGExec() const;

		void			beSigned(const Bureaucrat& bureau);
		void			execute(const Bureaucrat& bureau) const;
		virtual void	executeForm(void) const = 0;

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

	class NotSigned: public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

std::ostream	&operator<<(std::ostream& os, const AForm& other);
