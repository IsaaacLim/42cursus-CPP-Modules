#include "ClassContacts.hpp"

/*
** getline vs cin
**	getline: std lib function in the string header file
**	cin: Instance(object) of istream class
** getline needs to flush newline char out (can also use cin.ignore())
*/
std::string ft_getstring(std::string prompt)
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

	buf = ft_getstring("First name\t: ");
	while (!new_contact.setFirstName(buf))
		buf = ft_getstring("First name\t: ");
	buf = ft_getstring("Last name\t: ");
	while (!new_contact.setLastName(buf))
		buf = ft_getstring("Last name\t: ");
	new_contact.nickName = ft_getstring("Nickname\t: ");
	buf = ft_getstring("Phone number\t: ");
	while (!new_contact.setNumber(buf))
		buf = ft_getstring("Phone number\t: ");
	new_contact.secret = ft_getstring("Darkest secret\t: ");
	return (new_contact);
}

void ft_search(Contacts contact[MAX_CONTACTS])
{
	int idx = 0;
	std::string firstName;
	std::string lastName;
	std::string nickName;

	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		firstName = contact[i].getFirstName();
		lastName = contact[i].getLastName();
		nickName = contact[i].nickName;
		std::cout << "|" << std::setw(WIDTH) << i + 1;
		std::cout << "|" << std::setw(WIDTH) << firstName;
		std::cout << "|" << std::setw(WIDTH) << lastName;
		std::cout << "|" << std::setw(WIDTH) << nickName << "|" << std::endl;
	}
	std::cout << "Entry index\t: ";
	do
	{
		while (!(std::cin >> idx))
		{
			std::cout << "Not a valid index. Input numbers only\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Entry index\t: ";
		}
		if (idx < 1 || idx > MAX_CONTACTS)
		{
			std::cout << "Out of range. (Input 1 - 8)" << std::endl;
			std::cout << "Entry index\t: ";
		}
	} while (idx < 1 || idx > MAX_CONTACTS);
	if (idx > 0 && idx <= MAX_CONTACTS)
	{
		idx -= 1;
		std::cout << "First name\t: " << contact[idx].getFirstName() << std::endl;
		std::cout << "Last name\t: " << contact[idx].getLastName() << std::endl;
		std::cout << "Nick name\t: " << contact[idx].nickName << std::endl;
		std::cout << "Phone number\t: " << contact[idx].getNumber() << std::endl;
		std::cout << "Darkest secret\t: " << contact[idx].secret << std::endl;
	}
}

int ft_execute(Contacts contact[MAX_CONTACTS])
{
	char command[7];
	static int index;

	std::cout << "Input command: ";
	std::cin >> command;
	if (!strncmp(command, "ADD", 4))
	{
		contact[index % MAX_CONTACTS] = ft_add();
		index++;
	}
	else if (!strncmp(command, "SEARCH", 7))
		ft_search(contact);
	else if (!strncmp(command, "EXIT", 5))
		return 1;
	else
		std::cout << "\x1B[31mCommands: ADD / SEARCH / EXIT\033[0m" << std::endl;
	return 0;
}

int main(int argc, char *argv[])
{
	Contacts contact[MAX_CONTACTS];

	if (argc != 1)
	{
		std::cout << "No arguements" << std::endl;
		return 1;
	}
	while (1)
	{
		if (ft_execute(contact) == 1)
			break;
	}
	return 0;
}
