#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap::ClapTrap()
{
	std::cout << "ScavTrap: Default constructor called" << std::endl;
	return;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap: Constructor with 'name' parameter called" << std::endl;
	std::cout << "Character Info:\n\tName\t\t: " << this->_name << std::endl;
	std::cout << "\tHitPoints\t: " << this->_hitPoints << std::endl;
	std::cout << "\tEnergyPoints\t: " << this->_energyPoints << std::endl;
	std::cout << "\tAttackDamage\t: " << this->_attackDamage << std::endl;
	return;
}

ScavTrap::ScavTrap(ScavTrap const &other) : ClapTrap()
{
	std::cout << "ScavTrap: Copy constructor called" << std::endl;
	*this = other;
	return;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap: Destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &rhs)
{
	std::cout << "ScavTrap: Assignment operator called" << std::endl;

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
	std::cout << "ScavTrap: " << this->_name << " attack " << target;
	std::cout << ", causing " << this->_attackDamage << " points of damage!";
	std::cout << std::endl;
	return;
}

void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap: " << this->_name;
	std::cout << " has enterred in Gate Keeper mode" << std::endl;
	return;
}
