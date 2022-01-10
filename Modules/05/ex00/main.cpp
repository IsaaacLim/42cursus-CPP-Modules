#include "Bureaucrat.hpp"

#define YELLOW "\033[3;33m"
#define RESET "\033[0m"

void	ft_title(std::string str, char c)
{
	std::cout << c << YELLOW "=============== " << str << " ===============\n" RESET;
}

int main(void)
{
	Bureaucrat jacob("Jacob", 3);
	Bureaucrat mike("Mike", 148);

	//Increment grade until it's too high
	ft_title("TEST 1, Increment until too high", '\n');
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

	//Decrement grade until it's too low
	ft_title("TEST 2, Decrement until too low", '\n');
	for (int i = 0; i < 4; i++)
	{
		try
		{
			mike.decrementGrade();
			std::cout << mike;
		}
		catch (Bureaucrat::GradeTooLowException &e) //made public to allow specific catch
		{
			std::cerr << mike.getName() << ", " << e.what() << "\n";
		}
		catch (std::exception &e)
		{
			std::cerr << mike.getName() << ", " << e.what() << "\n";
		}
	}

	//Instantiate an unusable Bureaucrat
	ft_title("TEST 3, Instantiate an unsuable Bureaucrat", '\n');
	try
	{
		Bureaucrat molly("Molly", 0);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << "\n";
	}

	//Copy an unusable Bureaucrat
	ft_title("TEST 4, Copy an unusable Bureaucrat", '\n');
	try
	{
		Bureaucrat new_mike(mike);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << "\n";
	}
	std::cout << "\n";
}
