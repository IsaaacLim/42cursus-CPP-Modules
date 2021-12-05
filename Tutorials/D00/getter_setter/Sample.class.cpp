#include <iostream>
#include "Sample.class.hpp"

Sample::Sample(void)
{
	std::cout << "Constructor called" << std::endl;

	this->setFoo(0);
	std::cout << "Private initial value from contructor: " << this->getFoo() << std::endl;
	return;
}

Sample::~Sample(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}

int	Sample::getFoo(void) const
{
	return this->_foo;
}

//Now the private member attribute wil only be changed if it's positive
void	Sample::setFoo(int v)
{
	if (v >= 0)
		this->_foo = v;
	return;
}
