#include <iostream>
#include "Megaphone.class.hpp"

Megaphone::Megaphone(void)
{
	std::cout << "Constructro called" << std::endl;
	return;
}

Megaphone::~Megaphone(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}
