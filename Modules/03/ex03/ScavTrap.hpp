#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

//prevent ambiguity when referring to ClapTrap variables
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
	~ScavTrap(void);

	ScavTrap &operator=(ScavTrap const &rhs);

	void attack(std::string const &target);
	void guardGate(void);
};

#endif
