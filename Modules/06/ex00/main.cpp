#include "Convert.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
		std::cout << "Input ONE argument to be converted" << std::endl;
	else
	{
		Convert instance(argv[1]);
		std::cout << instance << std::endl;
	}
}
