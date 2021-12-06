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

std::string Contacts::getNickName(void) const
{
	return this->_nickName;
}

void Contacts::setNickName(std::string str)
{
	this->_nickName = str;
	return;
}

int Contacts::getNumber(void) const
{
	return this->_number;
}

bool Contacts::setNumber(int num)
{
	if (num >= 0)
		this->_number = num;
	return (true);
}
