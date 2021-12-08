#include "Zombie.hpp"
#include <sstream>

/*
** sso.clear() to allow set numbers to increment
*/
Zombie *zombieHorde(int N, std::string name)
{
	Zombie *heap_instances = new Zombie[N];
	std::stringstream sso;
	std::string sso_name;

	for (int i = 0; i < N; i++)
	{
		sso << name + "#";
		sso << i + 1;
		sso >> sso_name;
		sso.clear();
		heap_instances[i].setName(sso_name);
		heap_instances[i].announce();
	}

	return (heap_instances);
}
