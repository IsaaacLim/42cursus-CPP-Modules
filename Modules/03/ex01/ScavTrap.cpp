#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap::ClapTrap()
{
	std::cout << PURPLE "ScavTrap: Default constructor called" RESET << std::endl;
	return;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << PURPLE "ScavTrap: Constructor with 'name' parameter called\n";
	std::cout << "Character Info:\n\tName\t\t: " << this->_name << "\n";
	std::cout << "\tHitPoints\t: " << this->_hitPoints << "\n";
	std::cout << "\tEnergyPoints\t: " << this->_energyPoints << "\n";
	std::cout << "\tAttackDamage\t: " << this->_attackDamage << "\n" RESET;
	std::cout << std::endl;
	return;
}

ScavTrap::ScavTrap(ScavTrap const &other) : ClapTrap()
{
	std::cout << PURPLE "ScavTrap: Copy constructor called" RESET << std::endl;
	*this = other;
	return;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << PURPLE "ScavTrap: Destructor called" RESET << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &rhs)
{
	std::cout << PURPLE "ScavTrap: Assignment operator called" RESET << std::endl;

	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_hitPoints = rhs.getHitPoints();
		this->_energyPoints = rhs.getEnergyPoints();
		this->_attackDamage = rhs.getAttackDamage();
	}
	return *this;
}

void ScavTrap::attack(std::string const &target)
{
	std::cout << PURPLE "ScavTrap: " << this->_name << " attack " << target;
	std::cout << ", causing " << this->_attackDamage << " points of damage!" RESET ;
	std::cout << std::endl;
	return;
}

void ScavTrap::guardGate(void)
{
	std::cout << PURPLE "ScavTrap: " << this->_name;
	std::cout << " has enterred in Gate Keeper mode" RESET << std::endl;
	return;
}
