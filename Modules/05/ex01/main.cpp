// #include "Bureaucrat.hpp" //Causes class redefinition
#include "Form.hpp"

void ex00_test()
{
	std::cout << "========== EX00 TESTS ==========\n";
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
			std::cerr << jacob.getName() << ", " << e.what() << "\n";
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
			std::cerr << mike.getName() << ", " << e.what() << "\n";
		}
		catch (std::exception &e)
		{
			std::cerr << mike.getName() << ", " << e.what() << "\n";
		}
	}
	std::cout << "\n";
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

int main(void)
{
	// ex00_test();

	std::cout << "\n========== EX01 TESTS ==========\n";
	Bureaucrat mike("Mike", 50);
	Form f_general("General", false, 100, 10);
}
