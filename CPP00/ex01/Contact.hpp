#pragma once

#include <string>
#include <iostream>
#include <cstdlib>

class Contact {
private:
	std::string	_firstname;
	std::string	_lastname;
	std::string	_nickname;
	std::string	_phonenumber;
	std::string	_darkestsecret;
	std::string	_getField(std::string fieldPrompt);
public:
	Contact();
	~Contact();
	std::string get_first_name();
	std::string get_last_name();
	std::string get_nickname();
	std::string	get_phone_number();
	std::string get_darkest_secret();
	void		setContact(int nfield, std::string fieldPrompt);
};
