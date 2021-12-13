#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : virtual public ClapTrap
{
private:
	/* data */
public:
	ScavTrap(void);
	ScavTrap(std::string name);
	ScavTrap(ScavTrap const &other);
	virtual ~ScavTrap(void);

	ScavTrap &operator=(ScavTrap const &rhs);

	void guardGate(void);
};

#endif
