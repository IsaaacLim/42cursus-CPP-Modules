#include "Character.hpp"

Character::Character(std::string const &name) : _name(name), _equipped(0)
{
	for (int i = 0; i < SKILL_AMOUNT; i++)
		this->_materias[i] = '\0';
	std::cout << "Character\t: Constructor with 'name' parameter\n";
}

Character::Character(const Character &other)
{
	*this = other;
	std::cout << "Character\t: Copy constructor\n";
}

Character::~Character(void)
{
	std::cout << "Character\t: Destructor" << std::endl;
}

Character &Character::operator=(const Character &rhs)
{
	this->_name = rhs.getName();
	//_materials?
	std::cout << "Character\t: Assignation operator\n";
	return *this;
}

std::string const &Character::getName() const { return this->_name; }

void Character::equip(AMateria *m)
{
	if (!m)
		std::cout << "Character\t: Invalid skill\n";
	else if (this->_equipped < SKILL_AMOUNT)
	{
		this->_materias[this->_equipped++] = m;
		std::cout << "Character\t: Equipped new " << m->getType() << " skill\n";
	}
	else
		std::cout << "Character\t: Skill capacity full\n";
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= this->_equipped || this->_materias[idx] == '\0')
		std::cout << "Character\t: Skill doesn't exist, nothing to unequip\n";
	else
	{
		std::cout << "Character\t: Unequipped " << this->_materias[idx]->getType() << "\n";
		if (idx == SKILL_AMOUNT - 1)
			this->_materias[idx] = '\0';
		for (; idx < SKILL_AMOUNT - 1; idx++)
		{
			this->_materias[idx] = this->_materias[idx + 1];
			this->_materias[idx + 1] = '\0';
		}
		this->_equipped--;
	}
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= this->_equipped || this->_materias[idx] == '\0')
		std::cout << "Character\t: Skill doesn't exist, nothing to use\n";
	else
	{
		std::cout << "Character\t: ";
		this->_materias[idx]->use(target); //I ice bolt myself?
	}
}
