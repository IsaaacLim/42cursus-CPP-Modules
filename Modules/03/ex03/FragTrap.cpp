#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	std::cout << YELLOW "FragTrap: Default constructor called" RESET << std::endl;
	return;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;

	std::cout << YELLOW "FragTrap: Constructor with 'name' parameter called\n";
	std::cout << "Character Info:\n\tName\t\t: " << this->_name << "\n";
	std::cout << "\tHitPoints\t: " << this->_hitPoints << "\n";
	std::cout << "\tEnergyPoints\t: " << this->_energyPoints << "\n";
	std::cout << "\tAttackDamage\t: " << this->_attackDamage << "\n" RESET;
	std::cout << std::endl;
	return;
}

FragTrap::FragTrap(FragTrap const &other) : ClapTrap()
{
	std::cout << YELLOW "FragTrap: Copy constructor called, copying ";
	std::cout << this->_name << RESET << std::endl;
	*this = other;
	return;
}

FragTrap::~FragTrap(void)
{
	std::cout << YELLOW "FragTrap: Destructor called" RESET << std::endl;
	return;
}

FragTrap &FragTrap::operator=(FragTrap const &rhs)
{
	std::cout << YELLOW "FragTrap: Assignment operator called" RESET << std::endl;

	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_hitPoints = rhs.getHitPoints();
		this->_energyPoints = rhs.getEnergyPoints();
		this->_attackDamage = rhs.getAttackDamage();
	}
	return *this;
}

void FragTrap::attack(std::string const &target)
{
	std::cout << YELLOW "FragTrap: " << this->_name << " attack " << target;
	std::cout << ", causing " << this->_attackDamage << " points of damage!";
	std::cout << RESET << std::endl;
	return;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << YELLOW "FragTrap: " << this->_name << " calls for a high five!";
	std::cout << RESET << std::endl;
	return;
}
