#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : virtual public ClapTrap
{
	//Will create ambiguity for DiamondTrap
protected:
	// std::string _name;
	// int _hitPoints;
	// int _energyPoints;
	// int _attackDamage;

public:
	ScavTrap(void);
	ScavTrap(std::string name);
	ScavTrap(ScavTrap const &other);
	virtual ~ScavTrap(void);

	ScavTrap &operator=(ScavTrap const &rhs);

	void attack(std::string const &target);
	void guardGate(void);
};

#endif
