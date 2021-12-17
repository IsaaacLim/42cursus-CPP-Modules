#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "Brain.hpp"
#include <iostream>

class Animal
{
protected:
	std::string type;

public:
	Animal(void);
	Animal(const Animal &animal);
	virtual ~Animal(void);
	Animal &operator=(const Animal &animal);

	virtual void makeSound(void) const;

	std::string getType(void) const;
	virtual Brain *getBrain(void) const = 0;
};

class WrongCat : public Animal
{
public:
	WrongCat(void);
	WrongCat(const WrongCat &dog);
	~WrongCat(void);
	WrongCat &operator=(const WrongCat &dog);

	void makeSound(void) const;
};

#endif
