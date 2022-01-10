// #include "Bureaucrat.hpp" //Causes class redefinition
#include "Form.hpp"

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define BOLD "\033[1;33m"
#define ITALIC "\033[3;33m"
#define RESET "\033[0m"

void ft_title(std::string str, char c)
{
	std::cout << c << ITALIC "------ " << str << " ------\n" RESET;
}

void ex00_test()
{
	std::cout << BOLD "========== EX00 TESTS ==========\n" RESET;
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

int main(void)
{
	ex00_test();

	std::cout << BOLD "\n========== EX01 TESTS ==========\n" RESET;
	Bureaucrat mike("Mike", 50);
	Form f_general("General", false, 100, 10);
	Form f_classified("Classified", false, 20, 5);
	Form f_signed("Signed", true, 100, 10);
	Form forms[3] = {f_general, f_classified, f_signed};

	//Instances information
	ft_title("Instances Info", '\n');
	std::cout << mike;
	std::cout << f_general;
	std::cout << f_classified;
	std::cout << f_signed;

	//Form signing
	ft_title("Form Signing", '\n');
	for (int i = 0; i < 3; i++)
	{
		try
		{
			std::cout << GREEN;
			forms[i].beSigned(mike);
			std::cout << RESET;
		}
		catch (const std::exception &e)
		{
			std::cerr << RED;
			std::cerr << mike.getName() << " cannot sign [" << forms[i].getFormName();
			std::cerr << "] form because ";
			std::cerr << e.what() << '\n';
			std::cerr << RESET;
		}
	}

	//Form Information
	ft_title("Form Info", '\n');
	for (int i = 0; i < 3; i++)
		std::cout << forms[i];

	//Instantiate unusable form
	ft_title("Instantiate unusable form", '\n');
	try
	{
		Form f_wrong1("Wrong", false, 100, 0);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Form f_wrong2("Wrong", false, 151, 20);
	}
	catch (Form::GradeTooLowException &e) //Specific catch
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\n";
}
