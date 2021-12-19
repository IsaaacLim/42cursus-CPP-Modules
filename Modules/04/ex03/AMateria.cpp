#include "AMateria.hpp"

AMateria::AMateria(void) { std::cout << "AMateria\t: Default constructor\n"; }

AMateria::AMateria(std::string const &type) : type(type)
{
	std::cout << "AMateria\t: Constructor with 'type' parameter\n";
}

AMateria::AMateria(const AMateria &other)
{
	*this = other;
	std::cout << "AMateria\t: Copy constructor\n";
}

AMateria::~AMateria() { std::cout << "AMateria\t: Destructor" << std::endl; }

AMateria &AMateria::operator=(const AMateria &rhs)
{
	this->type = rhs.getType();
	std::cout << "AMateria\t: Assignment operator\n";
	return *this;
}

void AMateria::use(ICharacter &target)
{
	(void)target;
	std::cout << BLUE "-AMateria use function needs to be overriden-\n" RESET;
}

std::string const &AMateria::getType(void) const { return this->type; }
