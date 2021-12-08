#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name)
{
	this->_announce();
	return;
}

Zombie::~Zombie()
{
	std::cout << this->_name << " has died" << std::endl;
}

void Zombie::_announce(void) const
{
	std::cout << this->_name << " BraiiiiiiinnnzzzZ..." << std::endl;
}
