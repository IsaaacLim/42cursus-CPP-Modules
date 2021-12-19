#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure")
{
	this->type = "cure";
	std::cout << "Cure\t\t: Default constructor\n";
}

Cure::Cure(const Cure &other) : AMateria("cure")
{
	*this = other;
	std::cout << "Cure\t\t: Copy constructor";
}

Cure::~Cure(void) { std::cout << "Cure\t\t: Destructor" << std::endl; }

Cure &Cure::operator=(const Cure &rhs)
{
	this->type = rhs.getType();
	std::cout << "Cure\t\t: Assignment operator\n";
	return *this;
}

AMateria *Cure::clone() const
{
	AMateria *new_materia = new Cure();
	std::cout << "Cure\t\t: Clone\n";
	return new_materia;
}

void Cure::use(ICharacter &target)
{
	std::cout << GREEN "*Heals " << target.getName() << "'s wounds*\n" RESET;
}
