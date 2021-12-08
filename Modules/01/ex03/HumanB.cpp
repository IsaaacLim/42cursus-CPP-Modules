#include "HumanB.hpp"

/*
** Setting weapon through pointer
*/
HumanB::HumanB(std::string name) : _name(name)
{
	return;
}

HumanB::~HumanB(void) { return; }

void HumanB::attack(void) const
{
	std::cout << this->_name << " attack with his " << *this->_weapon << std::endl;
}

void HumanB::setWeapon(Weapon &club)
{
	this->_weapon = &club.getType();
}
