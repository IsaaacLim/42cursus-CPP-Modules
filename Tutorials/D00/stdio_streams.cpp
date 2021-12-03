#include <iostream>

int	main(void) {
	char buf[512];

	std::cout << "Hello World!" << std::endl;

	std::cout << "Input a word: ";
	std::cin >> buf;
	std::cout << "You entered: [" << buf << "]" << std::endl;

	return 0;
}
