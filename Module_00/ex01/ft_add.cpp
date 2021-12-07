#include "ClassContacts.hpp"

/*
** getline vs cin
**	getline: std lib function in the string header file
**	cin: Instance(object) of istream class
** getline needs to flush newline char out (can also use cin.ignore())
*/
static std::string ft_getstring(std::string prompt)
{
	std::string buf;

	std::cout << prompt;
	std::getline(std::cin >> std::ws, buf);
	return (buf);
}

Contacts ft_add()
{
	Contacts new_contact;
	std::string buf;

	do
	{
		buf = ft_getstring("First name\t: ");
	} while (!new_contact.setFirstName(buf));
	do
	{
		buf = ft_getstring("Last name\t: ");
	} while (!new_contact.setLastName(buf));
	new_contact.nickName = ft_getstring("Nickname\t: ");
	do
	{
		buf = ft_getstring("Phone number\t: ");

	} while (!new_contact.setNumber(buf));
	new_contact.secret = ft_getstring("Darkest secret\t: ");
	return (new_contact);
}
