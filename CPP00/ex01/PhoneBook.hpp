#pragma once

#include <cstring>
#include <cctype>
#include <cstdio>
#include <iomanip>
#include <ostream>
#include <strings.h>
#include "Contact.hpp"

class PhoneBook {
private:
	Contact 	_contacts[8];
	int			_index;
	bool		_checkIndex(int index);
	void		_getAllContacts();
	void		_getIndexContact(Contact Contact);

public:
	PhoneBook();
	~PhoneBook();
	void	add();
	void	search();
};
