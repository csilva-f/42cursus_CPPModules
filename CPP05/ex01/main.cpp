#include "Bureaucrat.hpp"

int main()
{
	std::cout << "TEST 1: OK" << std::endl;
	Bureaucrat	Bureau1("BureauT1", 25);
	std::cout << Bureau1;
	{
		try
		{
			Form Form1("FormT1", 30, 40);
			std::cout << Form1;
			Form1.beSigned(Bureau1);
			std::cout << Form1;
			Bureau1.signForm(Form1);
		}
		catch (std::exception &e)
		{
			std::cout << "Error!" << e.what() << std::endl;
		}
	}
	std::cout << std::endl << "TEST 2: NOK - Grade too low to sign" << std::endl;
	Bureaucrat Bureau2("BureauT2", 35);
	std::cout << Bureau2;
	{
		try
		{
			Form Form2("FormT2", 30, 40);
			std::cout << Form2;
			Form2.beSigned(Bureau2);
			Bureau2.signForm(Form2);
			std::cout << Form2;
		}
		catch (std::exception &e)
		{
			std::cout << "Error!" << e.what() << std::endl;
		}
	}
	std::cout << std::endl << "TEST 3: NOK - form grade to sign out of bounds (> 150)" << std::endl;
	Bureaucrat Bureau3("BureauT3", 25);
	std::cout << Bureau3;
	{
		try
		{
			Form Form3("FormT3", 160, 40);
			Form3.beSigned(Bureau3);
		}
		catch (Form::GradeTooHighException &e)
		{
			std::cout << "Error!" << e.what() << std::endl;
		}
		catch (Form::GradeTooLowException &e)
		{
			std::cout << "Error!" << e.what() << std::endl;
		}
	}
	std::cout << std::endl << "TEST 4: NOK - form grade to execute out of bounds (> 150)" << std::endl;
	Bureaucrat Bureau4("BureauT4", 25);
	std::cout << Bureau4;
	{
		try
		{
			Form Form4("FormT4", 30, 160);
			Form4.beSigned(Bureau4);
		}
		catch (Form::GradeTooHighException &e)
		{
			std::cout << "Error!" << e.what() << std::endl;
		}
		catch (Form::GradeTooLowException &e)
		{
			std::cout << "Error!" << e.what() << std::endl;
		}
	}
	std::cout << std::endl << "TEST 5: NOK - form grade to sign out of bounds (< 1)" << std::endl;
	Bureaucrat Bureau5("BureauT5", 25);
	std::cout << Bureau5;
	{
		try
		{
			Form Form5("FormT5", 0, 40);
			Form5.beSigned(Bureau5);
		}
		catch (Form::GradeTooHighException &e)
		{
			std::cout << "Error!" << e.what() << std::endl;
		}
		catch (Form::GradeTooLowException &e)
		{
			std::cout << "Error!" << e.what() << std::endl;
		}
	}
	std::cout << std::endl << "TEST 6: NOK - form grade to execute out of bounds (< 1)" << std::endl;
	Bureaucrat Bureau6("BureauT6", 25);
	std::cout << Bureau6;
	{
		try
		{
			Form Form6("FormT6", 30, 0);
			Form6.beSigned(Bureau6);
		}
		catch (Form::GradeTooHighException &e)
		{
			std::cout << "Error!" << e.what() << std::endl;
		}
		catch (Form::GradeTooLowException &e)
		{
			std::cout << "Error!" << e.what() << std::endl;
		}
	}
    return 0;
}
