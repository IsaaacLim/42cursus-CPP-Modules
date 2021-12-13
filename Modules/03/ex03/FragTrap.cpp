#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	std::cout << "FragTrap: Default constructor called" << std::endl;
	return;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;

	std::cout << "FragTrap: Constructor with 'name' parameter called" << std::endl;
	std::cout << "Character Info:\n\tName\t\t: " << this->_name << std::endl;
	std::cout << "\tHitPoints\t: " << this->_hitPoints << std::endl;
	std::cout << "\tEnergyPoints\t: " << this->_energyPoints << std::endl;
	std::cout << "\tAttackDamage\t: " << this->_attackDamage << std::endl;
	return;
}

FragTrap::FragTrap(FragTrap const &other) : ClapTrap()
{
	std::cout << "FragTrap: Copy constructor called, copying " << this->_name << std::endl;
	*this = other;
	return;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap: Destructor called" << std::endl;
	return;
}

FragTrap &FragTrap::operator=(FragTrap const &rhs)
{
	std::cout << "FragTrap: Assignment operator called" << std::endl;

	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_hitPoints = rhs.getHitPoints();
		this->_energyPoints = rhs.getEnergyPoints();
		this->_attackDamage = rhs.getAttackDamage();
	}
	return *this;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap: " << this->_name << " calls for a high five!" << std::endl;
	return;
}
