#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern intern;
	std::cout << std::endl << "TEST 1: Invalid form creation" << std::endl;
	Bureaucrat bureau1("BureauT1", 5);
	{
		try
		{
			AForm *form1;
			AForm *form2;
			form1 = intern.makeForm("FormT1", "target");
			form2 = intern.makeForm("FormT2", "target");

			std::cout << "Test 1.1: Execute form not signed" << std::endl;
			bureau1.executeForm(*form1);
			bureau1.executeForm(*form2);

			std::cout << "Test 1.2: Execute form with lower grade" << std::endl;
			bureau1.signForm(*form1);
			bureau1.executeForm(*form1);
			bureau1.signForm(*form2);
			bureau1.executeForm(*form2);

			std::cout << "Test 1.3: Execute form" << std::endl;
			bureau1.gradeIncrement();
			bureau1.executeForm(*form1);
			bureau1.executeForm(*form2);

			delete form1;
			delete form2;
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}

	}
	std::cout << std::endl << "TEST 2: ShrubberyCreation" << std::endl;
	Bureaucrat bureau2("BureauT2", 138);
	{
		AForm *form1;
		AForm *form2;
		form1 = intern.makeForm("Shrubbery Creation", "target");
		form2 = new ShrubberyCreationForm("target1");

		std::cout << "Test 2.1: Execute form not signed" << std::endl;
		bureau2.executeForm(*form1);
		bureau2.executeForm(*form2);

		std::cout << "Test 2.2: Execute form with lower grade" << std::endl;
		bureau2.signForm(*form1);
		bureau2.executeForm(*form1);
		bureau2.signForm(*form2);
		bureau2.executeForm(*form2);

		std::cout << "Test 2.3: Execute form" << std::endl;
		bureau2.gradeIncrement();
		bureau2.executeForm(*form1);
		bureau2.executeForm(*form2);

		delete form1;
		delete form2;
	}
	std::cout << std::endl << "TEST 3: RobotomyRequestForm" << std::endl;
	Bureaucrat bureau3("BureauT3", 46);
	{
		AForm *form1;
		AForm *form2;
		form1= intern.makeForm("Robotomy Request", "target");
		form2 = new RobotomyRequestForm("target1");

		std::cout << "Test 3.1: Execute form not signed" << std::endl;
		bureau3.executeForm(*form1);
		bureau3.executeForm(*form2);

		std::cout << "Test 3.2: Execute form with lower grade" << std::endl;
		bureau3.signForm(*form1);
		bureau3.executeForm(*form1);
		bureau3.signForm(*form2);
		bureau3.executeForm(*form2);

		std::cout << "Test 3.3: Execute form" << std::endl;
		bureau3.gradeIncrement();
		bureau3.executeForm(*form1);
		bureau3.executeForm(*form2);

		delete form1;
		delete form2;
	}
	std::cout << std::endl << "TEST 4: PresidentialPardonForm" << std::endl;
	Bureaucrat bureau4("BureauT4", 5);
	{
		AForm	*form1;
		AForm	*form2;
		form1 = intern.makeForm("Presidential Pardon", "target");
		form2 = new PresidentialPardonForm("target1");

		std::cout << "Test 4.1: Execute form not signed" << std::endl;
		bureau4.executeForm(*form1);
		bureau4.executeForm(*form2);

		std::cout << "Test 4.2: Execute form with lower grade" << std::endl;
		bureau4.signForm(*form1);
		bureau4.executeForm(*form1);
		bureau4.signForm(*form2);
		bureau4.executeForm(*form2);

		std::cout << "Test 4.3: Execute form" << std::endl;
		bureau4.gradeIncrement();
		bureau4.executeForm(*form1);
		bureau4.executeForm(*form2);

		delete form1;
		delete form2;
	}
	return 0;
}
