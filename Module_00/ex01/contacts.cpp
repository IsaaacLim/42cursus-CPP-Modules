#include "ClassContacts.hpp"

Contacts ft_add()
{
	Contacts add;
	std::string buf;

	std::cout << "First name: ";
	std::getline(std::cin >> std::ws, buf);
	add.setFirstName(buf);
	// if (!add.setFirstName(buf))
	// 	return (NULL);
	std::cout << "Written: " << add.getFirstName() << std::endl;
	return (add);
}

int ft_execute(Contacts contact[MAX_CONTACTS])
{
	char command[7];
	static int index;

	std::cout << "Input command: ";
	std::cin >> command;
	if (!strncmp(command, "ADD", 4))
	{
		contact[index] = ft_add();
		index++;
	}
	else if (!strncmp(command, "SEARCH", 7))
	{
		std::cout << "search" << std::endl;
	}
	else if (!strncmp(command, "EXIT", 5))
	{
		std::cout << "exit" << std::endl;
		return 1;
	}
	else
	{
		std::cout << "\x1B[31mCommands: ADD / SEARCH / EXIT\033[0m" << std::endl;
	}
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
	std::cout << "First name: " << contact[0].getFirstName() << std::endl;
	return 0;
}
