#include <iostream>

/*
** This file shows different syntaxes of how try-catch exceptions can be created
*/

// Basic overview
void test1()
{
	try
	{
		int num = 43;
		if (num != 42)
			throw std::exception(); //a class as itself
		else
			std::cout << "number is 42" << std::endl;
	}
	catch (const std::exception e) //can be passed by value
	{
		std::cerr << e.what() << '\n';
	}
}

// Doesn't contain try-catch, only throw
void test2a()
{
	int num = 43;
	if (num != 42)
		throw std::exception();
	else
	{
		std::cout << "number is 42" << std::endl;
	}
}

void test2()
{
	try
	{
		test2a();
	}
	catch (std::exception &e) //may be passed by reference
	{
		std::cerr << e.what() << "\n";
	}
}

void test3()
{

	class PEBKACException : public std::exception //polymorphism, sub-class of std::exception class
	{
	public:
		virtual const char *what() const throw()
		{
			return ("Problem exists between keyboard and chair");
		}
	};

	try
	{
		test2(); //gonna throw an exception

		//still reaches here and below although test2() failed
		// throw std::exception(); //general exception
		// throw(PEBKACException::exception()); //general exception
		throw PEBKACException(); //specific exception
	}
	catch (PEBKACException &e) //may be a specific catch
	{
		std::cerr << e.what() << "\n";
	}
	catch (std::exception &e) //or a generic catch
	{
		std::cerr << e.what() << " <- from test3\n";
	}
	catch (...) //general catch (catches all types of exceptions)
	{
		std::cerr << "caught by general exception\n";
	}
}

int main(void)
{
	// test1();
	// test2();
	test3();
}
