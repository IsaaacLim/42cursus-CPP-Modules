#include "Dog.hpp"

Dog::Dog(void)
{
	this->type = "Dog";
	std::cout << "Dog\t: Default constructor\n";
	this->_brain = new Brain();
}

Dog::Dog(const Dog &other) : AAnimal()
{
	*this = other;
	// this->_brain = dog.getBrain();
	std::cout << "Dog\t: Copy constructor\n";
}

Dog::~Dog(void)
{
	delete this->_brain;
	std::cout << "Dog\t: Destructor" << std::endl;
}

//Somehow With/Without get__() works the same (?)
Dog &Dog::operator=(const Dog &rhs)
{
	this->type = rhs.getType();
	// this->_brain = dog.getBrain();
	// *(this->_brain) = *(dog.getBrain());
	std::cout << "Dog\t: Assignment operator\n";
	return *this;
}

AAnimal &Dog::operator=(const AAnimal &rhs)
{
	this->type = rhs.getType();
	std::cout << "Anima\t: Assignment operator\n";
	return *this;
}

void Dog::makeSound(void) const { std::cout << this->type << " says Woof!\n"; }

Brain *Dog::getBrain(void) const { return this->_brain; }
