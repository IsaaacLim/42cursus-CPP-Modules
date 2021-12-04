#include <iostream>
#include "Sample.class.hpp"

Sample::Sample(void) { //Constructor

	std::cout << "Constructor called" << std::endl;

	this->foo = 42; //This
	std::cout << "this->foo: " << this->foo << std::endl;

	this->bar();

	return;

}

Sample::~Sample(void) { //Destructor

	std::cout << "Destructor called" << std::endl;
	return;
	
}

void	Sample::bar(void) { //Function

	std::cout << "Member function bar called" << std::endl;
	return ;

}
