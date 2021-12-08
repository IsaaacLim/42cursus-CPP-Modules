#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
private:
	std::string _name;
	void _announce(void) const;

public:
	Zombie(std::string name);
	~Zombie();
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif
