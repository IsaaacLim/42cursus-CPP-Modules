#include "Poly.hpp"

int main()
{
	// Constructors --------------------
	std::cout << YELLOW;
	const Animal *meta = new Animal();

	std::cout << CYAN;
	const Animal *dog = new Dog();

	std::cout << PURPLE;
	const Animal *cat = new Cat();

	std::cout << RED;
	const Animal *wrongcat = new WrongCat();
	std::cout << "\n" RESET;

	// Polymorphism Tests --------------------
	std::cout << CYAN "dog->getType()\t\t: " << dog->getType() << "\n";
	std::cout << PURPLE "cat->getType()\t\t: " << cat->getType() << "\n";
	std::cout << RED "wrongcat->getType()\t: " << wrongcat->getType() << "\n\n";

	std::cout << PURPLE "cat->makeSound()\t: ";
	cat->makeSound();
	std::cout << CYAN "dog->makeSound()\t: ";
	dog->makeSound();
	std::cout << YELLOW "meta->makeSound()\t: ";
	meta->makeSound();
	std::cout << RED "wrongcat->makeSound()\t: ";
	wrongcat->makeSound();
	std::cout << "\n" RESET;

	// Destructors --------------------
	std::cout << PURPLE;
	delete cat;

	std::cout << CYAN;
	delete dog;

	std::cout << YELLOW;
	delete meta;

	std::cout << RED;
	delete wrongcat;
}
