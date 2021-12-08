#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &club) : _name(name), _weapon(club.getType())
{
	return;
}

HumanA::~HumanA(void) { return; }

void HumanA::attack(void) const
{
	std::cout << this->_name << " attacks with his " << this->_weapon << std::endl;
	return;
}
