#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat jacob("Jacob", 3);
	Bureaucrat mike("Mike", 148);

	std::cout << "\n";

	//Increment grade until it's too high
	for (int i = 0; i < 4; i++)
	{
		try
		{
			jacob.incrementGrade();
			std::cout << jacob;
		}
		catch (const std::exception &e)
		{
			std::cerr << jacob.getName() << ", " << e.what() << "\n";
		}
	}
	std::cout << "\n";

	//Decrement grade until it's too low
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
			std::cerr << mike.getName() << ", " << e.what() << "\n";
		}
		catch (std::exception &e)
		{
			std::cerr << mike.getName() << ", " << e.what() << "\n";
		}
	}
	std::cout << "\n";

	//Instantiate unusable Bureaucrats
	try
	{
		Bureaucrat molly("Molly", 0);
		molly.decrementGrade();
		std::cout << molly;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what();
	}
	std::cout << "\n";
	try
	{
		Bureaucrat new_mike(mike);
		new_mike.incrementGrade();
		std::cout << new_mike;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what();
	}
	std::cout << "\n";
}
