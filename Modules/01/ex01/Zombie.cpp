#include "Zombie.hpp"

Zombie::Zombie() { return; }

Zombie::~Zombie()
{
	std::cout << this->_name << " has died" << std::endl;
	return;
}

void Zombie::announce(void) const
{
	std::cout << this->_name << " BraiiiiiiinnnzzzZ" << std::endl;
	return;
}

std::string Zombie::getName(void) const
{
	return this->_name;
}

void Zombie::setName(std::string name)
{
	this->_name = name;
	return;
}
