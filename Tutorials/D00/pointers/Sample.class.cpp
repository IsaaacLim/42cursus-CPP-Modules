#include <iostream>
#include "Sample.class.hpp"

//Everthing is the same here
Sample::Sample(void) : foo(0) //initializing foo with 0
{
	std::cout << "Constructor called" << std::endl;
	return;
}

Sample::~Sample(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}

void Sample::bar(void) const
{
	std::cout << "Member function bar called" << std::endl;
	return;
}
