#include "Poly.hpp"

int main()
{
	const Animal *meta = new Animal();
	const Animal *dog = new Dog();
	const Animal *cat = new Cat();
	const Animal *wrongcat = new WrongCat();

	std::cout << dog->getType() << " <- animal type\n";
	std::cout << cat->getType() << " <- animal type\n";
	std::cout << wrongcat->getType() << " <- animal type\n";
	cat->makeSound();
	dog->makeSound();
	meta->makeSound();
	wrongcat->makeSound();

	delete cat;
	delete dog;
	delete meta;
	delete wrongcat;
}
