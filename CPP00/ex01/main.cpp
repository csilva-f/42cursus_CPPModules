#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <algorithm>
#include <iostream>
#include <ostream>
#include <string>

int	main()
{
	std::string	cmd;
	PhoneBook	phonebook;

	std::cout << "The program will only allow the following commands: ADD, SEARCH and EXIT" << std::endl << std::endl;
	while (1)
	{
		std::cout << "Please specify a command: ";
		std::getline(std::cin, cmd);
		if (cmd == "EXIT")
			break;
		else if (cmd == "ADD")
			phonebook.add();
		else if (cmd == "SEARCH")
			phonebook.search();
		else
		 	std::cout << "Invalid command. Please try again." << std::endl;
		if (std::cin.eof())
		{
			std::cout << "Reached the end of the input."<< std::endl;
			return 0;
		}
		else if (std::cin.fail())
		{
			std::cout << "An error occurred while reading the input."<< std::endl;
			return 0;
		}
	}
	return 0;
}
