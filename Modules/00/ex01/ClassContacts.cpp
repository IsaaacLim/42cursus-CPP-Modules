#include "ClassContacts.hpp"

Contacts::Contacts(void) { return; }

Contacts::~Contacts(void) { return; }

std::string Contacts::getFirstName(void) const
{
	return this->_firstName;
}

bool Contacts::setFirstName(std::string str)
{
	for (int i = 0; str[i]; i++)
	{
		if (!isalpha(str[i]))
		{
			std::cout << "Only alphabets accepted" << std::endl;
			return (false);
		}
	}
	this->_firstName = str;
	return (true);
}

std::string Contacts::getLastName(void) const
{
	return this->_lastName;
}

bool Contacts::setLastName(std::string str)
{
	for (int i = 0; str[i]; i++)
	{
		if (!isalpha(str[i]))
		{
			std::cout << "Only alphabets accepted" << std::endl;
			return (false);
		}
	}
	this->_lastName = str;
	return (true);
}

std::string Contacts::getNumber(void) const
{
	return this->_number;
}

bool Contacts::setNumber(std::string num)
{
	for (int i = 0; num[i]; i++)
	{
		if (!isdigit(num[i]))
		{
			std::cout << "Only numbers accepted" << std::endl;
			return (false);
		}
	}
	this->_number = num;
	return (true);
}
