#include "ClassContacts.hpp"

static std::string ft_truncate(std::string str)
{
	str = str.erase((WIDTH - 1), str.length() - (WIDTH - 1));
	str.append(".");
	return (str);
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
		firstName = (firstName.length() > WIDTH) ? ft_truncate(firstName) : firstName;
		std::cout << "|" << std::setw(WIDTH) << firstName;
		lastName = (lastName.length() > WIDTH) ? ft_truncate(lastName) : lastName;
		std::cout << "|" << std::setw(WIDTH) << lastName;
		nickName = (nickName.length() > WIDTH) ? ft_truncate(nickName) : nickName;
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
	idx -= 1;
	std::cout << "First name\t: " << contact[idx].getFirstName() << std::endl;
	std::cout << "Last name\t: " << contact[idx].getLastName() << std::endl;
	std::cout << "Nick name\t: " << contact[idx].nickName << std::endl;
	std::cout << "Phone number\t: " << contact[idx].getNumber() << std::endl;
	std::cout << "Darkest secret\t: " << contact[idx].secret << std::endl;
}
