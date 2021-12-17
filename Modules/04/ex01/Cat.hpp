#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Cat : public Animal
{
private:
	Brain *_brain;

public:
	Cat(void);
	Cat(const Cat &cat);
	~Cat(void);
	Cat &operator=(const Cat &cat);

	void makeSound(void) const;
	Brain *getBrain(void) const;
};

#endif
