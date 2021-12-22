#include <string>
#include <iostream>

class Character
{
public:
	void sayHello(std::string const &target);
	virtual void virtual_sayHello(std::string const &target);
};

class Warrior : public Character
{
public:
	void sayHello(std::string const &target); //can override functions
	virtual void virtual_sayHello(std::string const &target);
};

class Cat
{
};

void Character::sayHello(std::string const &target)
{
	std::cout << "Hello " << target << " from Character(non virtual)" << std::endl;
}

void Character::virtual_sayHello(std::string const &target)
{
	std::cout << "Hello " << target << " from Character(virtual)" << std::endl;
}

void Warrior::sayHello(std::string const &target)
{
	std::cout << "Hello " << target << " from Warrior(non virtual)" << std::endl;
}

void Warrior::virtual_sayHello(std::string const &target)
{
	std::cout << "Hello " << target << " from Warrior(virtual)" << std::endl;
}

int main(void)
{
	Warrior *a = new Warrior();	  //Warrior is a Warrior
	Character *b = new Warrior(); //Warrior is a Character

	// Warrior *c = new Character(); // Character is not a Warrior
	// Character *d = new Cat(); //Cat is not even related to Character

	a->sayHello("Warrior");
	b->sayHello("Character");
	a->virtual_sayHello("Warrior");
	b->virtual_sayHello("Character");

	Character e = Warrior();
	e.virtual_sayHello("Character"); // virtual doesn't work here
}
