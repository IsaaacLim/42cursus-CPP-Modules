#include "Animal.hpp"

AAnimal::AAnimal(void) { std::cout << "AAnimal\t: Default constructor\n"; }

AAnimal::~AAnimal(void) { std::cout << "AAnimal\t: Destructor" << std::endl; }

std::string AAnimal::getType() const { return (this->type); }

WrongCat::WrongCat(void)
{
	this->type = "WrongCat";
	std::cout << "WrongCat: Default constructor\n";
}

WrongCat::WrongCat(const WrongCat &cat) : AAnimal()
{
	*this = cat;
	std::cout << "WrongCat: Copy constructor\n";
}

WrongCat::~WrongCat(void) { std::cout << "WrongCat: Destructor" << std::endl; }

WrongCat &WrongCat::operator=(const WrongCat &cat)
{
	this->type = cat.getType();
	std::cout << "WrongCat: Assignment operator\n";
	return *this;
}

void WrongCat::makeSound(void) const { std::cout << this->type << " says Woof!\n"; }
