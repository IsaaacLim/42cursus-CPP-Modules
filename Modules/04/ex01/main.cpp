#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define PURPLE "\033[0;35m"
#define CYAN "\033[0;36m"
#define RESET "\033[0m"

#define SIZE 4

int main(void)
{
	int i;
	Animal *animals[SIZE];

	// Constructors --------------------
	std::cout << CYAN;
	for (i = 0; i < SIZE / 2; i++)
		animals[i] = new Dog();
	std::cout << PURPLE;
	for (; i < SIZE; i++)
		animals[i] = new Cat();
	std::cout << RESET;
	// const Animal *wrongcat = new WrongCat(); //Can't be declared cuz it doesn't have getBrain()

	// Shallow & Deep Copy Test --------------------
	std::cout << "\n     ------ Shallow Copy ------\n";
	animals[0]->getBrain()->ideas[0] = "Am I a Pug?"; //initialize animal#1's idea#1
	std::cout << RED;
	std::cout << animals[0]->getType() << "#1's idea#1\t: " << animals[0]->getBrain()->ideas[0] << "\n";

	Animal *tmp = animals[1];							   //retain original pointer for animals[1] for correct free
	animals[1] = animals[0];							   //Shallow copy
	animals[1]->getBrain()->ideas[0] = "Am I a Frenchie?"; //initialize animal#2's idea#1

	std::cout << YELLOW;
	std::cout << animals[1]->getType() << "#2's idea#1\t: " << animals[1]->getBrain()->ideas[0] << "\n";
	std::cout << RED;
	std::cout << animals[0]->getType() << "#1's idea#1\t: " << animals[0]->getBrain()->ideas[0] << "\n";
	std::cout << RESET;

	animals[1] = tmp; //to point to previous memory for correct free

	std::cout << "\n     ------  Deep Copy  ------\n";
	animals[2]->getBrain()->ideas[99] = "Am I a Sphynx?"; //initialize animal#3's idea#1
	std::cout << GREEN;
	std::cout << animals[2]->getType() << "#1's idea#100\t: " << animals[2]->getBrain()->ideas[99] << "\n";
	std::cout << RESET;

	*animals[3] = *animals[2];							   //deep copy
	animals[3]->getBrain()->ideas[99] = "Am I a Persian?"; //initialize animal#2's idea#1

	std::cout << BLUE;
	std::cout << animals[3]->getType() << "#2's idea#100\t: " << animals[3]->getBrain()->ideas[99] << "\n";
	std::cout << GREEN;
	std::cout << animals[2]->getType() << "#1's idea#100\t: " << animals[2]->getBrain()->ideas[99] << "\n\n";
	std::cout << RESET;

	// Destructors --------------------
	std::cout << CYAN;
	for (i = 0; i < SIZE / 2; i++)
		delete animals[i];
	std::cout << PURPLE;
	for (; i < SIZE; i++)
		delete animals[i];
	std::cout << RESET;
}
