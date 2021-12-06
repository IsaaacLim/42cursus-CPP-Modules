#include <iostream>
#include "Sample.class.hpp"

Sample::Sample(void)
{
	std::cout << "Constructor called" << std::endl;
	Sample::_nbInst += 1;
	return;
}

Sample::~Sample(void)
{
	std::cout << "Destructor called" << std::endl;
	Sample::_nbInst -= 1;
	return;
}

/*
** Can't use 'this' for non-member attribute
** For members, c++ systematically pass a parameter of an instance of the class in the back
*/
int Sample::getNbInst(void)
{
	return Sample::_nbInst;
}

//Gotta initialize statics in a constructor
int Sample::_nbInst = 0;
