// #include "Bureaucrat.hpp" //class redefinition error during compilation
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

#include <unistd.h> //for sleep()

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define BOLD "\033[1;33m"
#define ITALIC "\033[3;33m"
#define BLUE "\033[0;34m"
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

void ex01_test()
{
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
			std::cout << RED;
			std::cerr << mike.getName() << " cannot sign [" << forms[i].getFormName();
			std::cerr << "] form because ";
			std::cerr << e.what() << '\n';
			std::cout << RESET;
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
		std::cerr << RED;
		std::cerr << penHolder.getName() << " couldn't sign [";
		std::cerr << form->getFormName() << "] form: ";
		std::cerr << e.what() << "\n\n" RESET;
	}
}

void ex02_test()
{
	std::cout << BOLD "\n========== EX02 TESTS ==========\n" RESET;
	Bureaucrat supervisor("Supervisor", 100);
	Bureaucrat manager("Manager", 50);
	Bureaucrat bigBoss("Big Boss", 5);
	ShrubberyCreationForm shrubForm("shrub_tree");
	RobotomyRequestForm roboForm("BrokenBot");
	PresidentialPardonForm pardonForm("Defendant");

	//Instances information
	ft_title("Instances Info", '\n');
	std::cout << supervisor;
	std::cout << manager;
	std::cout << bigBoss;
	std::cout << shrubForm;
	std::cout << roboForm;
	std::cout << pardonForm;

	//Form signing
	ft_title("Form Signing", '\n');
	signForm(&shrubForm, supervisor);
	signForm(&roboForm, supervisor);
	signForm(&roboForm, manager);
	signForm(&pardonForm, manager);
	signForm(&pardonForm, bigBoss);

	ft_title("Form Execution Result", '\n');
	std::cout << BLUE "Shrubbery ---------------\n" RESET;
	try
	{
		manager.executeForm(shrubForm);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << BLUE "\nRobotomy ---------------\n" RESET;
	for (int i = 0; i < 10; i++)
	{
		try
		{
			bigBoss.executeForm(roboForm);
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
		sleep(1);
	}

	std::cout << BLUE "\nPrez Pardon ---------------\n" RESET;
	try
	{
		bigBoss.executeForm(pardonForm);
		manager.executeForm(pardonForm);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED "Failed to pardon: ";
		std::cerr << e.what() << "\n" RESET;
	}
	std::cout << "\n";
}

Form *createForm(Intern intern, std::string const &formName, std::string const &target)
{
	Form *rrf = NULL;
	try
	{
		std::cerr << "\n" GREEN;
		rrf = intern.makeForm(formName, target);
		std::cerr << RESET "\n";
	}
	catch (const std::exception &e)
	{
		std::cerr << RED;
		std::cerr << e.what() << '\n';
		std::cerr << RESET "\n";
	}
	return (rrf);
}

int main()
{
	// ex00_test();
	// ex01_test();
	// ex02_test();
	std::cout << BOLD "\n========== EX03 TESTS ==========\n" RESET;
	Bureaucrat bigBoss("Big Boss", 5);
	Intern someRandomIntern;
	Form *shrub;
	Form *robo;
	Form *pardon;

	ft_title("Creating forms", '\n');
	shrub = createForm(someRandomIntern, "Flowers Please", "Defendant");
	shrub = createForm(someRandomIntern, "shrubbery creation", "home");
	robo = createForm(someRandomIntern, "robotomy request", "borkenBot");
	pardon = createForm(someRandomIntern, "presidential pardon", "Defendant");

	ft_title("Instances Info", '\n');
	std::cout << bigBoss;
	std::cout << *shrub;
	std::cout << *robo;
	std::cout << *pardon;

	ft_title("Presidential Pardon Form Signing", '\n');
	signForm(pardon, bigBoss);

	ft_title("Presidential Pardon Form Execution", '\n');
	try
	{
		bigBoss.executeForm(*pardon);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\n";
	delete shrub;
	delete robo;
	delete pardon;
}
