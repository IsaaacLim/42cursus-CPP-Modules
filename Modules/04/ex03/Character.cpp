#include "Character.hpp"

Character::Character(void) : _equipped(0)
{
	for (int i = 0; i < SKILL_AMOUNT; i++)
		this->_materias[i] = NULL;
	std::cout << "Character\t: Default constructor\n";
}

Character::Character(std::string const &name) : _name(name), _equipped(0)
{
	for (int i = 0; i < SKILL_AMOUNT; i++)
		this->_materias[i] = NULL;
	std::cout << "Character\t: Constructor with 'name' parameter\n";
}

Character::Character(const Character &other)
{
	*this = other;
	std::cout << "Character\t: Copy constructor\n";
}

Character::~Character(void)
{
	for (int i = 0; i < this->_equipped; i++)
		delete this->_materias[i];
	std::cout << "Character\t: Destructor" << std::endl;
}

Character &Character::operator=(const Character &rhs)
{
	this->_name = rhs.getName();
	for (int i = 0; i < this->_equipped; i++)
		delete this->_materias[i];
	this->_equipped = 0;
	for (int i = 0; i < rhs._equipped; i++)
		this->equip(rhs._materias[i]->clone());
	for (int i = this->_equipped; i < SKILL_AMOUNT; i++)
		this->_materias[i] = NULL;
	std::cout << "Character\t: Assignation operator\n";
	return *this;
}

std::string const &Character::getName() const { return this->_name; }

void Character::equip(AMateria *m)
{
	if (!m)
	{
		std::cout << RED "Character\t: Invalid skill\n" RESET;
		return;
	}
	else if (this->_equipped < SKILL_AMOUNT)
	{
		for (int i = 0; i < this->_equipped; i++)
		{
			if (this->_materias[i]->getType() == m->getType())
			{
				delete m;
				std::cout << RED "Character\t: Similar skill is already equipped\n" RESET;
				return;
			}
		}
		this->_materias[this->_equipped++] = m;
		std::cout << GREEN "Character\t: Equipped new " << m->getType() << " skill\n" RESET;
	}
	else
	{
		delete m;
		std::cout << RED "Character\t: Skill capacity full\n" RESET;
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= this->_equipped || this->_materias[idx] == NULL)
		std::cout << RED "Character\t: Skill doesn't exist, nothing to unequip\n" RESET;
	else
	{
		std::cout << GREEN "Character\t: Unequipped " << this->_materias[idx]->getType() << "\n" RESET;
		// delete this->_materias[idx];
		if (idx == SKILL_AMOUNT - 1)
			this->_materias[idx] = NULL;
		for (; idx < SKILL_AMOUNT - 1; idx++)
		{
			this->_materias[idx] = this->_materias[idx + 1];
			this->_materias[idx + 1] = NULL;
		}
		this->_equipped--;
	}
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= this->_equipped || this->_materias[idx] == NULL)
		std::cout << RED "Character\t: Skill doesn't exist, nothing to use\n" RESET;
	else
	{
		std::cout << GREEN "Character\t: " << this->_name << " " RESET;
		this->_materias[idx]->use(target);
	}
}
