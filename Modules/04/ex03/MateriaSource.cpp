#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) { std::cout << "MSource\t: Default constructor\n"; }

MateriaSource::MateriaSource(const MateriaSource &other)
{
	*this = other;
	std::cout << "MSource\t: Copy constructor\n";
}

MateriaSource::~MateriaSource(void) { std::cout << "MSource\t: Destructor" << std::endl; }

MateriaSource &MateriaSource::operator=(const MateriaSource &rhs)
{
	// this->....
	std::cout << "MSource\t: Assignmation operator\n";
	return *this;
}

void MateriaSource::learnMateria(AMateria *skill)
{
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
}
