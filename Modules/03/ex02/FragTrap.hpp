#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : public ClapTrap
{
private:
	/* data */
public:
	FragTrap(void);
	FragTrap(std::string name);
	FragTrap(FragTrap const &other);
	~FragTrap(void);

	FragTrap &operator=(FragTrap const &rhs);

	void highFivesGuys(void);
};

#endif
