#include "Sample.class.hpp"

Sample::Sample(void)
{
	std::cout << "Constructor called" << std::endl;
	return;
}

Sample::~Sample(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}

void Sample::bar(char const c) const
{
	std::cout << "Member func called with char overload: " << c << std::endl;
	return;
}

void Sample::bar(int const n) const
{
	std::cout << "Member func called with int overload: " << n << std::endl;
	return;
}

void Sample::bar(float const z) const
{
	std::cout << "Member func called with float overload: " << z << std::endl;
	return;
}

void Sample::bar(Sample const &i) const
{
	(void)i;
	std::cout << "Member func called with Sample class_ overload" << std::endl;
	return;
}
