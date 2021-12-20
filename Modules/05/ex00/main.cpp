#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat mike("Mike", 148);
	Bureaucrat jacob("jacob", 3);

	for (int i = 0; i < 4; i++)
	{
		try
		{
			mike.decrementGrade();
			std::cout << mike;
		}
		catch (std::exception &e)
		{
			std::cerr << e.what();
		}
	}
	for (int i = 0; i < 4; i++)
	{
		try
		{
			jacob.incrementGrade();
			std::cout << jacob;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what();
		}
	}
}
