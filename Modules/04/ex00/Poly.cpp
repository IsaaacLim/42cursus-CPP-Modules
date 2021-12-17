#include "Poly.hpp"

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

Dog::Dog(void)
{
	this->type = "Dog";
	std::cout << "Dog\t: Default constructor\n";
}

Dog::Dog(const Dog &dog) : Animal()
{
	*this = dog;
	std::cout << "Dog\t: Copy constructor\n";
}

Dog::~Dog(void) { std::cout << "Dog\t: Destructor" << std::endl; }

Dog &Dog::operator=(const Dog &dog)
{
	this->type = dog.getType();
	std::cout << "Dog\t: Assignment operator\n";
	return *this;
}

void Dog::makeSound(void) const { std::cout << this->type << " says Woof!\n"; }

Cat::Cat(void)
{
	this->type = "Cat";
	std::cout << "Cat\t: Default constructor\n";
}

Cat::Cat(const Cat &cat) : Animal()
{
	*this = cat;
	std::cout << "Cat\t: Copy constructor\n";
}

Cat::~Cat(void) { std::cout << "Cat\t: Destructor" << std::endl; }

Cat &Cat::operator=(const Cat &cat)
{
	this->type = cat.getType();
	std::cout << "Cat\t: Assignment operator\n";
	return *this;
}

void Cat::makeSound(void) const { std::cout << this->type << " says Meow!\n"; }

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
