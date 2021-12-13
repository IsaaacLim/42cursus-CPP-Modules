#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
private:
	std::string _privateName;

public:
	DiamondTrap(void);
	DiamondTrap(std::string name);
	DiamondTrap(DiamondTrap const &other);
	~DiamondTrap(void);

	DiamondTrap &operator=(DiamondTrap const &rhs);

	void whoAmI(void);

	std::string getPrivateName(void) const;
	void setPrivateName(std::string name);

	//attack() from scavtrap
};

#endif
