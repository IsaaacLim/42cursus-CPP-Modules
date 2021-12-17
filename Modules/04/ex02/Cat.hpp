#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Cat : public AAnimal
{
private:
	Brain *_brain;

public:
	Cat(void);
	Cat(const Cat &other);
	~Cat(void);
	Cat &operator=(const Cat &rhs);
	AAnimal &operator=(const AAnimal &rhs);

	void makeSound(void) const;
	Brain *getBrain(void) const;
};

#endif
