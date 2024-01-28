#include "Contact.hpp"
#include <string>

Contact::Contact() {
}

Contact::~Contact() {
}

std::string	Contact::get_first_name(){
	return this->_firstname;
}

std::string	Contact::get_last_name(){
	return this->_lastname;
}

std::string	Contact::get_nickname(){
	return this->_nickname;
}

std::string	Contact::get_phone_number(){
	return this->_phonenumber;
}

std::string	Contact::get_darkest_secret(){
	return this->_darkestsecret;
}

std::string	Contact::_getField(std::string fieldPrompt)
{
	std::string	field;

	do {
		std::cout << fieldPrompt;
		std::getline(std::cin, field);
		if (std::cin.fail()) {
			std::cout << "Error encountered while reading the input." << std::endl;
			std::exit(1);
		}
		else if (std::cin.eof())
			exit(1);
	} while (field.empty());
	return field;
}

void	Contact::setContact(int nfield, std::string fieldPrompt)
{
	switch (nfield) {
		case 1:
				this->_firstname = this->_getField(fieldPrompt);
				break;
		case 2:
				this->_lastname = this->_getField(fieldPrompt);
				break;
		case 3:
				this->_nickname = this->_getField(fieldPrompt);
				break;
		case 4:
				this->_phonenumber = this->_getField(fieldPrompt);
				break;
		case 5:
				this->_darkestsecret = this->_getField(fieldPrompt);
				break;
	}
}
