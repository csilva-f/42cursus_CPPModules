#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	Bureaucrat	bur1("Dom", 30);
	Bureaucrat	bur2("Jack", 10);
	Form		form1;
	Form		form2("Driving Licence Form", 20, 50);

	std::cout << "///////////////////////// BUREAUCRATS /////////////////////////" << std::endl;
	std::cout << bur1;
	std::cout << bur2;

	std::cout << "///////////////////////// FORMS /////////////////////////" << std::endl;
	std::cout << form1;
	std::cout << form2;

	std::cout << "-------------- 1. Sign a default form twice" << std::endl;
	form1.beSigned(bur1);
	std::cout << form1;
	form1.beSigned(bur1);
	std::cout << form1;

	std::cout << "-------------- 2. Sign a form with grade by 2 different bureaucrats" << std::endl;
	form2.beSigned(bur1);
	std::cout << form2;
	form2.beSigned(bur2);
	std::cout << form2;

	std::cout << "-------------- 3. Try to create a form with a grade lower than 150" << std::endl;
	Form	form3("Wrong form", 180, 30);
	Form	form4("Wroooong", 40, 200);

	std::cout << "-------------- 4. Try to create a form with a grade higher than 1" << std::endl;
	Form	form5("High form", 0, 30);
	Form	form6("Higheeeeer", 40, -1);

	return 0;
}
