#include "Poly.hpp"

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define PURPLE "\033[0;35m"
#define CYAN "\033[0;36m"
#define RESET "\033[0m"

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
	std::cout << CYAN "DOG\ngetType()\t: " << dog->getType() << "\n";
	std::cout << "makeSound()\t: ";
	dog->makeSound();

	std::cout << PURPLE "CAT\ngetType()\t: " << cat->getType() << "\n";
	std::cout << "makeSound()\t: ";
	cat->makeSound();

	std::cout << RED "WRONGCAT\ngetType()\t: " << wrongcat->getType() << "\n";
	std::cout << "makeSound()\t: ";
	wrongcat->makeSound();

	std::cout << YELLOW "META\ngetType()\t: " << meta->getType() << "\n";
	std::cout << "makeSound()\t: ";
	meta->makeSound();

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
