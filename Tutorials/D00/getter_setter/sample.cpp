#include <iostream>
#include "Sample.class.hpp"

int main()
{
	Sample instance;

	instance.setFoo(42);
	std::cout << "Private foo set to: " << instance.getFoo() << std::endl;
	instance.setFoo(-42); //won't change the value
	std::cout << "Private foo set to: " << instance.getFoo() << std::endl;
	return 0;
}
