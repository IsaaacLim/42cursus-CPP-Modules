#include "Zombie.hpp"

Zombie *newZombie(std::string name)
{
	Zombie *clone = new Zombie(name);

	return (clone);
}
