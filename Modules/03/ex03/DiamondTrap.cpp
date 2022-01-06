#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
{
	std::cout << GREEN "DiamondTrap: Default constructor called" RESET << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), _privateName(name)
{
	this->_hitPoints = FragTrap::_hitPoints;		 //not
	this->_energyPoints = ScavTrap::_energyPoints; //setting
	this->_attackDamage = FragTrap::_attackDamage; //correctly
	std::cout << GREEN "DiamondTrap: Constructor with 'name' parameter called\n";
	std::cout << "Character Info:\n\tName\t\t: " << this->_privateName << "\n";
	std::cout << "\tHitPoints\t: " << this->_hitPoints << "\n";
	std::cout << "\tEnergyPoints\t: " << this->_energyPoints << "\n";
	std::cout << "\tAttackDamage\t: " << this->_attackDamage << "\n" RESET;
	std::cout << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &other) : ClapTrap(), FragTrap(), ScavTrap()
{
	std::cout << GREEN "DiamondTrap: Copy constructor called" RESET << std::endl;
	*this = other;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << GREEN "DiamondTrap: Destructor called" RESET << std::endl;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &rhs)
{
	std::cout << GREEN "DiamondTrap: Assignation operator called" RESET << std::endl;

	if (this != &rhs)
	{
		this->_privateName = rhs.getPrivateName();
		this->_name = rhs.getName();
		this->_hitPoints = rhs.getHitPoints();
		this->_energyPoints = rhs.getEnergyPoints();
		this->_attackDamage = rhs.getAttackDamage();
	}
	return *this;
}

void DiamondTrap::attack(std::string const &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void)
{
	std::cout << GREEN "DiamondTrap: Who Am I? " << std::endl;
	std::cout << "\tPrivate name\t: " << this->_privateName << std::endl;
	std::cout << "\tClapTrap name\t: " << this->_name  << RESET << std::endl;
}

std::string DiamondTrap::getPrivateName(void) const
{
	return this->_privateName;
}

void DiamondTrap::setPrivateName(std::string name)
{
	std::cout << GREEN "DiamondTrap: " << this->_privateName << " change its private";
	std::cout << " name to" << name << RESET << std::endl;
	this->_privateName = name;
}
