#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137), _target("target")
{
	std::cout << "ShrubberyCreationForm default constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target): AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm constructr with target " << target << " called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other): AForm(other), _target(other._target)
{
	std::cout << "ShrubberyCreationForm copy constructor called." << std::endl;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
		this->_target = other._target;
	std::cout << "ShrubberyCreationForm copy assignment operator called." << std::endl;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called." << std::endl;
}

void	ShrubberyCreationForm::executeForm() const
{
	std::ofstream	file;
	std::string		filename = this->_target + "_shrubbery";

	file.open(filename.c_str(), std::ofstream::out);
	if (!file.is_open())
		throw std::runtime_error("Error occurred while opening the file.");
	file <<
	"                                                        .\n"
	"                                             .         ;\n"
	"                .              .              ;%     ;;\n"
	"                  ,           ,                :;%  %;\n"
	"                   :         ;                   :;%;'     .,\n"
	"          ,.        %;     %;            ;        %;'    ,;\n"
	"            ;       ;%;  %%;        ,     %;    ;%;    ,%'\n"
	"             %;       %;%;      ,  ;       %;  ;%;   ,%;'\n"
	"              ;%;      %;        ;%;        % ;%;  ,%;'\n"
	"               `%;.     ;%;     %;'         `;%%;.%;'\n"
	"                `:;%.    ;%%. %@;        %; ;@%;%'\n"
	"                   `:%;.  :;bd%;          %;@%;'\n"
	"                     `@%:.  :;%.         ;@@%;'\n"
	"                       `@%.  `;@%.      ;@@%;\n"
	"                         `@%%. `@%%    ;@@%;\n"
	"                           ;@%. :@%%  %@@%;\n"
	"                             %@bd%%%bd%%:;\n"
	"                               #@%%%%%:;;\n"
	"                               %@@%%%::;\n"
	"                               %@@@%(o);  . '\n"
	"                               %@@@o%;:(.,'\n"
	"                           `.. %@@@o%::;\n"
	"                              `)@@@o%::;\n"
	"                               %@@(o)::;\n"
	"                              .%@@@@%::;\n"
	"                              ;%@@@@%::;.\n"
	"                             ;%@@@@%%:;;;.\n"
	"                         ...;%@@@@@%%:;;;;,..\n";
	file.close();
}
