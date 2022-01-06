#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	std::cout << BLUE "ClapTrap: Default constructor called" RESET << std::endl;
	return;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(10)
{
	std::cout << BLUE "ClapTrap: Constructor with 'name' parameter called\n";
	std::cout << "Character Info:\n\tName\t\t: " << this->_name << "\n";
	std::cout << "\tHitPoints\t: " << this->_hitPoints << "\n";
	std::cout << "\tEnergyPoints\t: " << this->_energyPoints << "\n";
	std::cout << "\tAttackDamage\t: " << this->_attackDamage << "\n" RESET;
	std::cout << std::endl;
	return;
}

ClapTrap::ClapTrap(ClapTrap const &other)
{
	std::cout << BLUE "ClapTrap: Copy constructor called" RESET << std::endl;
	*this = other;
	return;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << BLUE "ClapTrap: Destructor called" RESET << std::endl;
	return;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs)
{
	std::cout << BLUE "ClapTrap: Assignment operator called" RESET << std::endl;

	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_hitPoints = rhs.getHitPoints();
		this->_energyPoints = rhs.getEnergyPoints();
		this->_attackDamage = rhs.getAttackDamage();
	}
	return *this;
}

void ClapTrap::attack(std::string const &target)
{
	std::cout << BLUE "ClapTrap: " << this->_name << " attack " << target;
	std::cout << ", causing " << this->_attackDamage << " points of damage!" RESET;
	std::cout << std::endl;
	return;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	this->_hitPoints -= amount;
	std::cout << BLUE "ClapTrap: " << this->_name << " received " << amount;
	std::cout << " of damage. HitPoints remaining: " << this->_hitPoints;
	std::cout << RESET << std::endl;
	return;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	this->_hitPoints += amount;
	std::cout << BLUE "ClapTrap: " << this->_name << " restored " << amount;
	std::cout << " of hitpoints. HitPoints remaining: " << this->_hitPoints;
	std::cout << RESET << std::endl;
	return;
}

std::string ClapTrap::getName(void) const { return this->_name; }

int ClapTrap::getHitPoints(void) const { return this->_hitPoints; }

int ClapTrap::getEnergyPoints(void) const { return this->_energyPoints; }

int ClapTrap::getAttackDamage(void) const { return this->_attackDamage; }

void ClapTrap::setName(std::string name)
{
	std::cout << BLUE "ClapTrap: " << this->_name << " changed its name to ";
	std::cout << name << RESET << std::endl;
	this->_name = name;
}
