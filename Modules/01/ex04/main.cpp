#include "ClassReplace.hpp"

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cout << "Input <filename> <str1> <str2>" << std::endl;
		return (1);
	}
	try
	{
		Replace::ft_replace(argv[1], argv[2], argv[3]);
	}
	catch (char const *e)
	{
		std::cerr << "error: " << e << std::endl;
	}
}
