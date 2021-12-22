// #include "Bureaucrat.hpp" //Causes class redefinition
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

#include <unistd.h>

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define RESET "\033[0m"

void printLabel(std::string label)
{
	std::cout << YELLOW "\n------ " << label << " ------\n" RESET;
}

void ex00_test()
{
	std::cout << YELLOW "========== EX00 TESTS ==========\n" RESET;
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

void ex01_test()
{
	std::cout << YELLOW "\n========== EX01 TESTS ==========\n" RESET;
	Bureaucrat mike("Mike", 50);
	Form f_general("General", false, 100, 10);
	Form f_classified("Classified", false, 20, 5);
	Form f_signed("Signed", true, 100, 10);
	Form forms[3] = {f_general, f_classified, f_signed};

	//Instances information
	printLabel("Instances Info");
	std::cout << mike;
	std::cout << f_general;
	std::cout << f_classified;
	std::cout << f_signed;

	//Form signing
	printLabel("Form Signing");
	for (int i = 0; i < 3; i++)
	{
		try
		{
			forms[i].beSigned(mike);
		}
		catch (const std::exception &e)
		{
			std::cerr << mike.getName() << " cannot sign [" << forms[i].getFormName();
			std::cerr << "] form because ";
			std::cerr << e.what() << '\n';
		}
	}

	//Form Information
	printLabel("Form Info");
	for (int i = 0; i < 3; i++)
		std::cout << forms[i];

	//Instantiate unusable form
	printLabel("Instantiate unusable form");
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

void signForm(Form *form, Bureaucrat penHolder)
{
	try
	{
		std::cout << "\n";
		form->beSigned(penHolder);
		std::cout << "\n";
	}
	catch (const std::exception &e)
	{
		std::cerr << penHolder.getName() << " couldn't sign [";
		std::cerr << form->getFormName() << "] form: ";
		std::cerr << e.what() << "\n\n";
	}
}

int main()
{
	// ex00_test();
	// ex01_test();

	std::cout << YELLOW "\n========== EX02 TESTS ==========\n" RESET;
	Bureaucrat supervisor("Supervisor", 100);
	Bureaucrat manager("Manager", 50);
	Bureaucrat bigBoss("Big Boss", 5);
	ShrubberyCreationForm shrubForm("shrub_tree");
	RobotomyRequestForm roboForm("BrokenBot");

	//Instances information
	printLabel("Instances Info");
	std::cout << supervisor;
	std::cout << manager;
	std::cout << bigBoss;
	std::cout << shrubForm;
	std::cout << roboForm;

	//Form signing
	printLabel("Form Signing");
	signForm(&shrubForm, supervisor);
	signForm(&roboForm, supervisor);
	signForm(&roboForm, manager);

	printLabel("Form Execution Result");
	try
	{
		shrubForm.execute(manager);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\n";
	for (int i = 0; i < 10; i++)
	{
		try
		{
			roboForm.execute(bigBoss);
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
		sleep(1);
	}

	std::cout << "\n";
}
