#include <iostream>
#include "Sample.class.hpp"

Sample::Sample(float const f) : pi(f), qd(42)
{

	std::cout << "Contructor called" << std::endl;
	return;
}

Sample::~Sample(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}

//Having const here tells the compiler that
//	this member function won't alter the current instance
void Sample::bar(void) const
{
	std::cout << "this->pi = " << this->pi << std::endl;
	std::cout << "this->qd = " << this->qd << std::endl;

	// this->qd = 42; //this won't compile
	return;
}
