#include "Classes.hpp"
#include <iostream>
#include <cstdlib>
#include <exception>
#include <typeinfo>

Base *generate(void)
{
	int random;
	Base *base = NULL;

	srand(time(NULL));
	random = rand() % 3;
	std::cout << "Randomly generated class: ";
	switch (random)
	{
	case 0:
		std::cout << "A\n";
		base = new A;
		break;
	case 1:
		std::cout << "B\n";
		base = new B;
		break;
	case 2:
		std::cout << "C\n";
		base = new C;
		break;
	default:
		std::cout << "???\n";
		break;
	}
	return (base);
}

void identify(Base *p)
{
	std::cout << "------ Using Pointer ------\n";
	std::cout << "Identified as class\t: ";
	if (dynamic_cast<A *>(p) != NULL)
		std::cout << "A\n";
	else if (dynamic_cast<B *>(p) != NULL)
		std::cout << "B\n";
	else if (dynamic_cast<C *>(p) != NULL)
		std::cout << "C\n";
	else
		std::cout << "???\n";
}

void identify(Base &p)
{
	std::cout << "------ Using Reference ------\n";
	std::cout << "Identified as class\t: ";
	try
	{
		dynamic_cast<A &>(p);
		std::cout << "A\n";
	}
	catch (const std::exception &e)
	{
		try
		{
			dynamic_cast<B &>(p);
			std::cout << "B\n";
		}
		catch (const std::exception &e)
		{
			try
			{
				dynamic_cast<C &>(p);
				std::cout << "C\n";
			}
			catch (const std::exception &e)
			{
				std::cout << "???\n";
			}
		}
	}
}

int main(void)
{
	Base *ptr = generate();
	identify(ptr);
	std::cout << "\n";
	Base &ref = *generate();
	identify(ref);

	delete ptr;
	delete &ref;
}
