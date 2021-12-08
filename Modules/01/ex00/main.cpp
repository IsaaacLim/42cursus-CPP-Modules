#include "Zombie.hpp"

int main(void)
{
	Zombie *heap_instance;

	heap_instance = newZombie("Heap-Zombie");
	randomChump("Stack-Zombie");

	delete heap_instance;

	return 0;
}
