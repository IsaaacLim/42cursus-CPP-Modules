#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon
{
private:
	std::string _type;

public:
	Weapon(std::string type);
	~Weapon(void);

	std::string const &getType(void) const;
	void setType(std::string const &type);
};

#endif
