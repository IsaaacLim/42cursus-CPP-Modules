#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : public ClapTrap
{
private:
	/* data */
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
