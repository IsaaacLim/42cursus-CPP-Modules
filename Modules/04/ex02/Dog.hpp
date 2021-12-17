#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog : public AAnimal
{
private:
	Brain *_brain;

public:
	Dog(void);
	Dog(const Dog &other);
	~Dog(void);
	Dog &operator=(const Dog &rhs);
	AAnimal &operator=(const AAnimal &rhs);

	void makeSound(void) const;
	Brain *getBrain(void) const;
};

#endif
