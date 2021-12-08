#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)
{
	return;
}

HumanB::~HumanB(void) { return; }

void HumanB::attack(void) const
{
	std::cout << this->_name << " attack with his " << *this->_weapon << std::endl;
}

void HumanB::setWeapon(const Weapon &club)
{
	this->_weapon = &club.getType();
}
