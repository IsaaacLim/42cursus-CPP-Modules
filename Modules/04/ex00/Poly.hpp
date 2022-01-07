#ifndef POLY_HPP
#define POLY_HPP

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define PURPLE "\033[0;35m"
#define CYAN "\033[0;36m"
#define RESET "\033[0m"

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
