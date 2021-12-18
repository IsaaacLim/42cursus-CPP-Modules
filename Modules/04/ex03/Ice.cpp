#include "Ice.hpp"

Ice::Ice(void)
{
	this->type = "ice";
	std::cout << "Ice\t: Default constructor\n";
}

Ice::Ice(const Ice &other) : AMateria()
{
	*this = other;
	std::cout << "Ice\t: Copy constructor\n";
}

Ice::~Ice(void) { std::cout << "Ice\t: Destructor" << std::endl; }

Ice &Ice::operator=(const Ice &rhs)
{
	this->type = rhs.getType();
	std::cout << "Ice\t: Assignment operator\n";
	return *this;
}

AMateria *Ice::clone() const
{
	AMateria *new_materia = new Ice();
	std::cout << "Ice\t: Clone\n";
	return new_materia;
}

void Ice::use(ICharacter &target)
{
	std::cout << "*Shoots an ice bolt at " << target.getName() << "*\n";
}
