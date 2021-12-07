#ifndef CLASSCONTACTS_HPP
#define CLASSCONTACTS_HPP

#include <iostream>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <iomanip>
#include <limits>

#define MAX_CONTACTS 8
#define WIDTH 10

class Contacts
{
public:
	std::string nickName;
	std::string secret;

	Contacts(void);
	~Contacts(void);

	std::string getFirstName(void) const;
	std::string getLastName(void) const;
	std::string getNumber(void) const;
	bool setFirstName(std::string);
	bool setLastName(std::string str);
	bool setNumber(std::string num);

private:
	std::string _firstName;
	std::string _lastName;
	std::string _number;
};

Contacts ft_add();
void ft_search(Contacts contact[MAX_CONTACTS]);

#endif
