#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
{
	std::cout << "DiamondTrap: Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), _privateName(name)
{
	this->_hitPoints = this->FragTrap::_hitPoints;		 //not
	this->_energyPoints = this->ScavTrap::_energyPoints; //setting
	this->_attackDamage = this->FragTrap::_attackDamage; //correctly
	std::cout << "DiamondTrap: Constructor with 'name' parameter called" << std::endl;
	std::cout << "Character Info:\n\tName\t\t: " << this->_privateName << std::endl;
	std::cout << "\tHitPoints\t: " << this->_hitPoints << std::endl;
	std::cout << "\tEnergyPoints\t: " << this->_energyPoints << std::endl;
	std::cout << "\tAttackDamage\t: " << this->_attackDamage << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &other) : ClapTrap(), FragTrap(), ScavTrap()
{
	std::cout << "DiamondTrap: Copy constructor called" << std::endl;
	*this = other;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap: Destructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &rhs)
{
	std::cout << "DiamondTrap: Assignation operator called" << std::endl;

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

void DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap: Who Am I? " << std::endl;
	std::cout << "\tPrivate name\t: " << this->_privateName << std::endl;
	std::cout << "\tClapTrap name\t: " << this->_name << std::endl;
}

std::string DiamondTrap::getPrivateName(void) const
{
	return this->_privateName;
}

void DiamondTrap::setPrivateName(std::string name)
{
	std::cout << "DiamondTrap: " << this->_privateName << " change its private";
	std::cout << " name to" << name << std::endl;
	this->_privateName = name;
}
