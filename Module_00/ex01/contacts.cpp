#include "ClassContacts.hpp"

static int ft_execute(Contacts contact[MAX_CONTACTS])
{
	char command[7];
	static int index;

	std::cout << "Input command: ";
	std::cin >> command;
	if (!strncmp(command, "ADD", 4))
		contact[index++ % MAX_CONTACTS] = ft_add();
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
	(void)argv;
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
