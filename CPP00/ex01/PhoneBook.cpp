#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook() {
	this->_index = 0;
}

PhoneBook::~PhoneBook() {
}

void	PhoneBook::add()
{
	std::cout << std::endl;
	this->_contacts[this->_index % 8].setContact(1, "Enter first name: ");
	this->_contacts[this->_index % 8].setContact(2, "Enter last name: ");
	this->_contacts[this->_index % 8].setContact(3, "Enter nickname: ");
	this->_contacts[this->_index % 8].setContact(4, "Enter phone number: ");
	this->_contacts[this->_index % 8].setContact(5, "Enter darkest secret: ");
	std::cout << this->_contacts[this->_index % 8].get_first_name() << " was successfully added to the phonebook." << std::endl << std::endl;
	this->_index++;
}

std::string	trimString(std::string field)
{
	if (field.size() > 10)
	{
		field.resize(10);
		field[field.size() - 1] = '.';
	}
	return field;
}

void	PhoneBook::_getIndexContact(Contact Contact)
{
	if (Contact.get_nickname().size())
	{
		std::cout << std::endl << "First name: " << Contact.get_first_name() << std::endl;
		std::cout << "Last name: " << Contact.get_last_name() << std::endl;
		std::cout << "Nickname: " << Contact.get_nickname() << std::endl;
		std::cout << "Phone number: " << Contact.get_phone_number() << std::endl;
		std::cout << "Darkest secret: " << Contact.get_darkest_secret() << std::endl << std::endl;
		return;
	}
	std::cout << "It was not possible to return the requested contact." << std::endl;
}

void	PhoneBook::_getAllContacts()
{
	if (!this->_contacts[0].get_first_name().size())
	{
		std::cout << "The phonebook is empty." << std::endl << std::endl;
		return;
	}
	std::cout << "|" << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname" << "|";
	std::cout << std::endl;
	for (int i = 0; i < 8 && this->_contacts[i].get_nickname().size(); i++)
	{
		std::cout << "|" << std::setw(10) << (i + 1) << "|";
		std::cout << std::setw(10) << trimString(this->_contacts[i].get_first_name()) << "|";
		std::cout << std::setw(10) << trimString(this->_contacts[i].get_last_name()) << "|";
		std::cout << std::setw(10) << trimString(this->_contacts[i].get_nickname()) << "|";
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void	PhoneBook::search()
{
	std::string	i;
	int			ni;

	std::cout << std::endl;
	if (!this->_contacts[0].get_first_name().size())
	{
		this->_getAllContacts();
		return;
	}
	this->_getAllContacts();
	while (!std::cin.eof())
	{
		std::cout << "Please specify the index of the contact you would like to see: ";
		std::getline(std::cin, i);
		if(i.empty())
		{
			std::cout << "You must specify one index." << std::endl;
			continue;
		}
		else if (i.size() != 1 || i[0] < '1' || i[0] > '8')
		{
			std::cout << "The inserted input is not valid. Please try again." <<std::endl;
			continue;
		}
		else
		{
			ni = std::atoi(i.c_str());
			this->_getIndexContact(this->_contacts[ni - 1]);
			break;
		}
	}
}
