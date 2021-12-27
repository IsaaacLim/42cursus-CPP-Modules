#include "Karen.hpp"

int main(int argc, char *argv[])
{
	Karen karen;

	if (argc != 2)
	{
		std::cout << "run: ./karenFilter <complain>" << std::endl;
		std::cout << "complains option: \"DEBUG\"/\"INFO\"/\"WARNING\"/\"ERROR\"" << std::endl;
		return 1;
	}
	karen.complain(argv[1]);
	return 0;
}
