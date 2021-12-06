#include <iostream>
#include "Megaphone.class.hpp"

int main(int argc, char *argv[])
{
	Megaphone instance;
	if (argc > 1)
		instance.ft_toupper(argv);
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;

	return 0;
}
