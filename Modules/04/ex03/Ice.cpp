#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice")
{
	this->type = "ice";
	std::cout << "Ice\t\t: Default constructor\n";
}

Ice::Ice(const Ice &other) : AMateria("ice")
{
	*this = other;
	std::cout << "Ice\t\t: Copy constructor\n";
}

Ice::~Ice(void) { std::cout << "Ice\t\t: Destructor" << std::endl; }

Ice &Ice::operator=(const Ice &rhs)
{
	this->type = rhs.getType();
	std::cout << "Ice\t\t: Assignment operator\n";
	return *this;
}

AMateria *Ice::clone() const
{
	AMateria *new_materia = new Ice();
	std::cout << "Ice\t\t: Clone\n";
	return new_materia;
}

void Ice::use(ICharacter &target)
{
	std::cout << GREEN "*Shoots an ice bolt at " << target.getName() << "*\n" RESET;
}
