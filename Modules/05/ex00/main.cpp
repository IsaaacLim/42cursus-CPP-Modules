#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat jacob("Jacob", 3);
	Bureaucrat mike("Mike", 148);

	std::cout << "\n";
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
	std::cout << "\n";
	for (int i = 0; i < 4; i++)
	{
		try
		{
			mike.decrementGrade();
			std::cout << mike;
		}
		catch (Bureaucrat::GradeTooLowException &e) //made public to allow specific catch
		{
			std::cerr << "beau-> ";
			std::cerr << e.what();
		}
		catch (std::exception &e)
		{
			std::cerr << e.what();
		}
	}
	std::cout << "\n";
}
