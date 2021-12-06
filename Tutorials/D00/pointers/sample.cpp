#include <iostream>
#include "Sample.class.hpp"

int main()
{
	Sample instance;			   //Stack instance
	Sample *instancep = &instance; //pointer instance

	//syntax of a pointer on member attribute on Sample class
	int Sample::*p = NULL;		   //pointer to take address of a member attr of Sample class
	void (Sample::*f)(void) const; //pointer on member functions

	//p takes the address of foo attr from Sample class
	//but we can can have many instances (eg: Sample::instance2)
	//it's not specified yet, from which instance the foo is from yet
	p = &Sample::foo;

	std::cout << "Value of member foo: " << instance.foo << std::endl;
	instance.*p = 21; //specify which instance p pointer is refering to
	std::cout << "Value of member foo: " << instance.foo << std::endl;
	instancep->*p = 42;
	std::cout << "Value of member foo: " << instance.foo << std::endl;

	f = &Sample::bar;

	(instance.*f)(); //again specify which instance
	(instancep->*f)();

	return 0;
}
