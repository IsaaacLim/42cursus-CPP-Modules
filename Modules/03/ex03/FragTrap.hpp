#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : virtual public ClapTrap
{
protected:
	// std::string _name; //will override clapTrap name
	int _hitPoints;
	int _energyPoints;
	int _attackDamage;

public:
	FragTrap(void);
	FragTrap(std::string name);
	FragTrap(FragTrap const &other);
	virtual ~FragTrap(void);

	FragTrap &operator=(FragTrap const &rhs);

	void attack(std::string const &target);
	void highFivesGuys(void);
};

#endif
