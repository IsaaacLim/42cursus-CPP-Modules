#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name)
{
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 10;
	std::cout << "ClapTrap: Default constructor called" << std::endl;
	std::cout << "Character Info:\n\tName\t\t: " << this->_name << std::endl;
	std::cout << "\tHitPoints\t: " << this->_hitPoints << std::endl;
	std::cout << "\tEnergyPoints\t: " << this->_energyPoints << std::endl;
	std::cout << "\tAttackDamage\t: " << this->_attackDamage << std::endl;
	return;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap: Destructor called" << std::endl;
	return;
}

void ClapTrap::attack(std::string const &target)
{
	std::cout << "ClapTrap: " << this->_name << " attack " << target;
	std::cout << ", causing " << this->_attackDamage << " points of damage!";
	std::cout << std::endl;
	return;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	this->_hitPoints -= amount;
	std::cout << "ClapTrap: " << this->_name << " received " << amount;
	std::cout << " of damage. HitPoints remaining: " << this->_hitPoints;
	std::cout << std::endl;
	return;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	this->_hitPoints += amount;
	std::cout << "ClapTrap: " << this->_name << " restored " << amount;
	std::cout << " of hitpoints. HitPoints remaining: " << this->_hitPoints;
	std::cout << std::endl;
	return;
}
