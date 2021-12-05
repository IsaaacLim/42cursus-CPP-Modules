#include <iostream>
#include "Sample.class.hpp"

int main()
{

	Sample instance;
	instance.publicFoo = 42;
	std::cout << "instance.publicFoo: " << instance.publicFoo << std::endl;
	instance.publicBar();

	//Privates doesn't work
	// instance._privateFoo = 42;
	// std::cout << "instance._privateFoo: " << instance._privateFoo << std::endl;
	// instance._privateBar();

	//Structs
	Sample2 instance2;
}
