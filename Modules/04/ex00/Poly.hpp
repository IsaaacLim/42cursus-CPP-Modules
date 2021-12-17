#ifndef POLY_HPP
#define POLY_HPP

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
};

class Dog : public Animal
{
public:
	Dog(void);
	Dog(const Dog &dog);
	~Dog(void);
	Dog &operator=(const Dog &dog);

	void makeSound(void) const;
};

class Cat : public Animal
{
public:
	Cat(void);
	Cat(const Cat &cat);
	~Cat(void);
	Cat &operator=(const Cat &cat);

	void makeSound(void) const;
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
