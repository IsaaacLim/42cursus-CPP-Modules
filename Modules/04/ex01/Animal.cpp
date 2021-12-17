#include "Animal.hpp"

Animal::Animal(void) { std::cout << "Animal\t: Default constructor\n"; }

Animal::Animal(const Animal &animal)
{
	*this = animal;
	std::cout << "Animal\t: Copy constructor\n";
}

Animal::~Animal(void) { std::cout << "Animal\t: Destructor" << std::endl; }

Animal &Animal::operator=(const Animal &animal)
{
	this->type = animal.getType();
	std::cout << "Animal\t: Assignment operator\n";
	return *this;
}

void Animal::makeSound(void) const { std::cout << "*silence from Animal*\n"; }

std::string Animal::getType() const { return (this->type); }

WrongCat::WrongCat(void)
{
	this->type = "WrongCat";
	std::cout << "WrongCat: Default constructor\n";
}

WrongCat::WrongCat(const WrongCat &cat) : Animal()
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
