#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::cout << "TEST 1: ShrubberyCreationForm" << std::endl;
	Bureaucrat Bureau1("BureauT1", 140);
	std::cout << Bureau1;
	AForm *Form1 = new ShrubberyCreationForm();
	{
		try
		{
			std::cout << "Test 1.1: Execute form not signed" << std::endl;
			Bureau1.executeForm(*Form1);

			std::cout << "Test 1.2: Execute with grade too low" << std::endl;;
			Bureau1.signForm(*Form1);
			Bureau1.executeForm(*Form1);

			std::cout << "Test 1.3: Execute form successfully" << std::endl;;
			Bureau1.gradeIncrement();
			Bureau1.gradeIncrement();
			Bureau1.gradeIncrement();
			Bureau1.executeForm(*Form1);
		}
		catch (std::exception &e)
		{
			std::cout << "Error!" << e.what() << std::endl;
		}
	}
	std::cout << std::endl << "TEST 2: RobotomyRequestForm" << std::endl;
	Bureaucrat Bureau2("BureauT2", 47);
	std::cout << Bureau2;
	AForm *Form2 = new RobotomyRequestForm();
	{
		try
		{
			std::cout << "Test 2.1: Execute form not signed" << std::endl;
			Bureau2.executeForm(*Form2);

			std::cout << "Test 2.2: Execute with grade too low" << std::endl;
			Bureau2.signForm(*Form2);
			Bureau2.executeForm(*Form2);

			std::cout << "Test 2.3: Execute form successfully" << std::endl;
			Bureau2.gradeIncrement();
			Bureau2.gradeIncrement();
			Bureau2.executeForm(*Form2);
		}
		catch (std::exception &e)
		{
			std::cout << "Error!" << e.what() << std::endl;
		}
	}
	std::cout << std::endl << "TEST 3: PresidentialPardonForm" << std::endl;
	Bureaucrat Bureau3("BureauT3", 7);
	std::cout << Bureau3;
	AForm *Form3 = new PresidentialPardonForm("target");
	{
		try
		{
			std::cout << "Test 3.1: Execute form not signed" << std::endl;
			Bureau3.executeForm(*Form3);

			std::cout << "Test 3.2: Execute with grade too low" << std::endl;
			Bureau3.signForm(*Form3);
			Bureau3.executeForm(*Form3);

			std::cout << "Test 3.3: Execute form successfully" << std::endl;
			Bureau3.gradeIncrement();
			Bureau3.gradeIncrement();
			Bureau3.executeForm(*Form3);
		}
		catch (std::exception &e)
		{
			std::cout << "Error!" << e.what() << std::endl;
		}
	}
	delete Form1;
	delete Form2;
	delete Form3;
	return 0;
}
