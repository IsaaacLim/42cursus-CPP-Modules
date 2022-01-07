#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "Brain.hpp"
#include <iostream>

/*
** Abstract classes only contains pure virtual functions
*/
class AAnimal
{
private:
	AAnimal(const AAnimal &animal); //could just leave it in public too and include the function in .cpp

protected:
	std::string type;

public:
	AAnimal(void);
	virtual ~AAnimal(void);
	virtual AAnimal &operator=(const AAnimal &animal) = 0;

	virtual void makeSound(void) const = 0;

	std::string getType(void) const;
	virtual Brain *getBrain(void) const = 0;
};

/*
** Class not usable anymore
**	No sufficient overriding functions
*/
class WrongCat : public AAnimal
{
public:
	WrongCat(void);
	WrongCat(const WrongCat &dog);
	~WrongCat(void);
	WrongCat &operator=(const WrongCat &dog);

	void makeSound(void) const;
};

#endif
