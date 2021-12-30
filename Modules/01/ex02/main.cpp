#include <iostream>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;			//refers to the class
	const char *stringDataPTR = str.data(); //refers to the actual data
	std::string &stringREF = str;

	std::cout << "str address\t: " << &str << std::endl;
	std::cout << "ptr address\t: " << stringPTR << std::endl;
	std::cout << "data address\t: " << (void *)stringDataPTR << std::endl;
	std::cout << "ref address\t: " << &stringREF << std::endl;

	std::cout << "ptr value\t: " << *stringPTR << std::endl;
	std::cout << "data value\t: " << str.data() << std::endl;
	std::cout << "ref value\t: " << stringREF << std::endl;
}
