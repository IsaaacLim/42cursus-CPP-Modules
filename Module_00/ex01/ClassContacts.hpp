#ifndef CLASS_CONTACTS_HPP
#define CLASS_CONTACTS_HPP

#include <iostream>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CONTACTS 8

class Contacts
{
public:
	Contacts(void);
	~Contacts(void);

	std::string getFirstName(void) const;
	std::string getLastName(void) const;
	std::string getNickName(void) const;
	int getNumber(void) const;
	std::string getSecret(void) const;
	bool setFirstName(std::string);
	bool setLastName(std::string str);
	void setNickName(std::string);
	bool setNumber(int);
	void setSecret(std::string);

private:
	std::string _firstName;
	std::string _lastName;
	std::string _nickName;
	int _number;
	std::string _secret;
};
#endif
