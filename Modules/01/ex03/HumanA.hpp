#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanA
{
private:
	std::string _name;
	std::string const &_weapon;

public:
	HumanA(std::string name, Weapon &club);
	~HumanA(void);

	void attack(void) const;
};

#endif
