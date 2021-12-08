#include "Zombie.hpp"

int main(void)
{
	Zombie *heap_instances;

	heap_instances = zombieHorde(10, "Zombie-Clone");

	delete[] heap_instances;
	return (0);
}
