#include "Cure.hpp"

Cure::Cure(void) { std::cout << "Cure\t: Default constructor\n"; }

Cure::Cure(const Cure &other) : AMateria()
{
	*this = other;
	std::cout << "Cure\t: Copy constructor";
}

Cure::~Cure(void) { std::cout << "Cure\t: Destructor" << std::endl; }

Cure &Cure::operator=(const Cure &rhs)
{
	this->type = rhs.getType();
	std::cout << "Cure\t: Assignment operator\n";
	return *this;
}

AMateria *Cure::clone() const
{
	AMateria *new_materia = new Cure();
	std::cout << "Cure\t: Clone\n";
	return new_materia;
}

void Cure::use(ICharacter &target)
{
	std::cout << "*Heals " << target.getName() << "'s wounds*\n";
}
