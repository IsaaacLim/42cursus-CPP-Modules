#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#define SIZE 4

int main(void)
{
	int i;
	AAnimal *animals[SIZE];

	for (i = 0; i < SIZE / 2; i++)
		animals[i] = new Dog();
	for (; i < SIZE; i++)
		animals[i] = new Cat();

	std::cout << "\n---------- IMPORTANT BIT ----------\n";
	std::cout << "     ------ Shallow Copy ------\n";
	animals[0]->getBrain()->ideas[0] = "Am I a Pug?"; //initialize animal#1's idea#1
	std::cout << animals[0]->getType() << "#1's idea#1\t: " << animals[0]->getBrain()->ideas[0] << "\n";
	AAnimal *tmp = animals[1];
	animals[1] = animals[0];							   //Shallow copy
	animals[1]->getBrain()->ideas[0] = "Am I a Frenchie?"; //initialize animal#2's idea#1
	std::cout << animals[1]->getType() << "#2's idea#1\t: " << animals[1]->getBrain()->ideas[0] << "\n";
	std::cout << animals[0]->getType() << "#1's idea#1\t: " << animals[0]->getBrain()->ideas[0] << "\n";
	animals[1] = tmp; //to point to previous memory for correct free

	std::cout << "     ------  Deep Copy  ------\n";
	animals[2]->getBrain()->ideas[0] = "Am I a Sphynx?"; //initialize animal#3's idea#1
	std::cout << animals[2]->getType() << "#1's idea#1\t: " << animals[2]->getBrain()->ideas[0] << "\n";
	*animals[3] = *animals[2];							  //deep copy
	animals[3]->getBrain()->ideas[0] = "Am I a Persian?"; //initialize animal#2's idea#1
	std::cout << animals[3]->getType() << "#2's idea#1\t: " << animals[3]->getBrain()->ideas[0] << "\n";
	std::cout << animals[2]->getType() << "#1's idea#1\t: " << animals[2]->getBrain()->ideas[0] << "\n";

	std::cout << "\n";
	// const Animal *wrongcat = new WrongCat(); //Can't be declared cuz it has no brain
	for (i = 0; i < SIZE; i++)
		delete animals[i];
}
