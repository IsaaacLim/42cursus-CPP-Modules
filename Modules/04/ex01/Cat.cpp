#include "Cat.hpp"

Cat::Cat(void)
{
	this->type = "Cat";
	std::cout << "Cat\t: Default constructor\n";
	this->_brain = new Brain();
}

Cat::Cat(const Cat &cat) : Animal()
{
	*this = cat;
	std::cout << "Cat\t: Copy constructor\n";
}

Cat::~Cat(void)
{
	delete this->_brain;
	std::cout << "Cat\t: Destructor" << std::endl;
}

//Somehow With/Without get__() works the same (?)
Cat &Cat::operator=(const Cat &cat)
{
	this->type = cat.getType();
	// this->_brain = cat.getBrain();
	// *this->_brain = *(cat.getType());
	std::cout << "Cat\t: Assignment operator\n";
	return *this;
}

void Cat::makeSound(void) const { std::cout << this->type << " says Meow!\n"; }

Brain *Cat::getBrain(void) const { return this->_brain; }
