#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanB
{
private:
	std::string _name;
	std::string const *_weapon;

public:
	HumanB(std::string name);
	~HumanB(void);

	void attack(void) const;

	void setWeapon(Weapon &club);
};

#endif
